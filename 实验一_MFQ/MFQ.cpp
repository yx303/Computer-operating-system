#include"MFQ.h"
int all_time = 0;
void Print(PCB &p)
{
	p.turn_weight_time = (double)p.turnaround_time / p.need_time;
	cout << p.name << "\t  " << p.need_time << "\t  " << p.arrive_time << "\t    " << p.finish_time << "\t     " << p.turnaround_time << "\t       " << fixed << setprecision(2) << p.turn_weight_time << endl;
}

queue<PCB> ProcessExecute(Queue* q, queue<PCB> &list)
{
	queue<PCB> temp;
	PCB p;
	while (!list.empty()||!q[0].process.empty() || !q[1].process.empty() || !q[2].process.empty() || !q[3].process.empty() || !q[4].process.empty()) {
		if (!list.empty()) {
			q[0].process.push(list.front());
			list.pop();
		}
		for (int i = 0; i < max; i++) {
			if (i == 0) {
				while (!q[i].process.empty()) {
					p = q[i].process.front();
					q[i].process.pop();
					if (all_time < p.arrive_time) all_time = p.arrive_time;//前一个进程执行完，后面的进程还没到
					Without(q, i, p, temp);
				}
			}
			else{
				Round(q, i, list, temp);
				if (!q[i].process.empty()) break;
			}
		}
	}
	return temp;
}

void Round(Queue* q, int i, queue<PCB>& list, queue<PCB>& temp)
{
	int difference_time = 0;
	PCB p;
	while (!q[i].process.empty()) {
		if (q[0].process.empty()) {
			if (!list.empty()) {
				difference_time = list.front().arrive_time - all_time;
				if (difference_time == 0) break;
				p = q[i].process.front();
				q[i].process.pop();
				if (difference_time <= q[i].time && difference_time <= p.left_time) {
					p.left_time -= difference_time;
					all_time += difference_time;
					if (p.left_time != 0) {
						if (difference_time == q[i].time) {
							if (i < max - 1) {
								q[i + 1].process.push(p);
								cout << "---------------------" << endl;
								cout << "第" << i << "队列，时间片:" << q[i].time << endl;
								cout << "进程没有执行完毕，需要添加到下一队列队尾，进程名:" << p.name << " 剩余服务时间：" << p.left_time << endl;
							}
							else {
								q[i].process.push(p);
								cout << "---------------------" << endl;
								cout << "第" << i << "队列，时间片:" << q[i].time << endl;
								cout << "进程没有执行完毕，需要添加到本队列队尾，进程名:" << p.name << " 剩余服务时间：" << p.left_time << endl;
							}
						}
						else {
							q[i].process.push(p);
							cout << "---------------------" << endl;
							cout << "第" << i << "队列，时间片:" << q[i].time << endl;
							cout << "进程没有执行完毕，需要添加到本队列队尾，进程名:" << p.name << " 剩余服务时间：" << p.left_time << endl;
						}
					}
					else {
						p.finish_time = all_time;
						p.turnaround_time = p.finish_time - p.arrive_time;
						temp.push(p);
						cout << "---------------------" << endl;
						cout << "此时时间：" << all_time << endl;
						cout << "服务完成并退出：" << p.name << endl;
						cout << "---------------------" << endl;
					}
					break;
				}
				Left(q, i, difference_time, p, temp);
			}
			else {
				p = q[i].process.front();
				q[i].process.pop();
				Without(q, i, p, temp);
			}
		}
	}
}

void Without(Queue* q, int i, PCB& p, queue<PCB>& temp)
{
	if (p.left_time <= q[i].time) {
		p.finish_time = all_time + p.left_time;
		p.turnaround_time = p.finish_time - p.arrive_time;
		all_time += p.left_time;
		temp.push(p);
		cout << "---------------------" << endl;
		cout << "此时时间：" << all_time << endl;
		cout << "服务完成并退出：" << p.name << endl;
		cout << "---------------------" << endl;
	}
	else {
		p.left_time -= q[i].time;
		all_time += q[i].time;
		if (i < max - 1) {
			q[i + 1].process.push(p);
			cout << "---------------------" << endl;
			cout << "第" << i << "队列，时间片:" << q[i].time << endl;
			cout << "进程没有执行完毕，需要添加到下一队列队尾，进程名:" << p.name << " 剩余服务时间：" << p.left_time << endl;
		}
		else {
			q[i].process.push(p);
			cout << "---------------------" << endl;
			cout << "第" << i << "队列，时间片:" << q[i].time << endl;
			cout << "进程没有执行完毕，需要添加到本队列队尾，进程名:" << p.name << " 剩余服务时间：" << p.left_time << endl;
		}
	}
}

void Left(Queue* q, int i, int time, PCB& p, queue<PCB>& temp)
{
	if ((time<q[i].time && time>p.left_time) || (time > q[i].time && time < p.left_time)) {
		if (q[i].time < p.left_time) {
			p.left_time -= q[i].time;
			all_time += q[i].time;
			if (i < max - 1) {
				q[i + 1].process.push(p);
				cout << "---------------------" << endl;
				cout << "第" <<i<<"队列，时间片:"<<q[i].time<< endl;
				cout << "进程没有执行完毕，需要添加到下一队列队尾，进程名:" << p.name << " 剩余服务时间：" << p.left_time << endl;
			}
			else {
				q[i].process.push(p);
				cout << "---------------------" << endl;
				cout << "第" << i << "队列，时间片:" << q[i].time << endl;
				cout << "进程没有执行完毕，需要添加到本队列队尾，进程名:" << p.name << " 剩余服务时间：" << p.left_time << endl;
			}
		}
		if (q[i].time > p.left_time) {
			all_time += p.left_time;
			p.finish_time = all_time;
			p.turnaround_time = p.finish_time - p.arrive_time;
			temp.push(p);
			cout << "---------------------" << endl;
			cout << "此时时间：" << all_time << endl;
			cout << "服务完成并退出：" << p.name << endl;
			cout << "---------------------" << endl;
		}
	}
	if (time >= q[i].time && time >= p.left_time) {
		if (p.left_time <= q[i].time) {
			p.finish_time = all_time + p.left_time;
			p.turnaround_time = p.finish_time - p.arrive_time;
			temp.push(p);
			cout << "---------------------" << endl;
			cout << "此时时间：" << all_time << endl;
			cout << "服务完成并退出：" << p.name << endl;
			cout << "---------------------" << endl;
			all_time += p.left_time;
		}
		else {
			p.left_time -= q[i].time;
			all_time += q[i].time;
			if (i < max - 1) {
				q[i + 1].process.push(p);
				cout << "---------------------" << endl;
				cout << "第" << i << "队列，时间片:" << q[i].time << endl;
				cout << "进程没有执行完毕，需要添加到下一队列队尾，进程名:" << p.name << " 剩余服务时间：" << p.left_time << endl;
			}
			else {
				q[i].process.push(p);
				cout << "---------------------" << endl;
				cout << "第" << i << "队列，时间片:" << q[i].time << endl;
				cout << "进程没有执行完毕，需要添加到本队列队尾，进程名:" << p.name << " 剩余服务时间：" << p.left_time << endl;
			}
		}
	}
}
