#include "Banker.h"

queue<int> que_pro;

void clear(queue<int> q)
{
	queue<int> empty;
	swap(q, empty);
}

bool compare(int* need, int* work)
{
	for (int i = 0; i < num; i++)
		if (need[i] > work[i])
			return false;
	return true;
}

void add(int* work, int* allo)
{
	for (int i = 0; i < num; i++)
		work[i] += allo[i];
}

void cha(int* avi, int* request)
{
	for (int i = 0; i < num; i++)
		avi[i] = avi[i] - request[i];
}

bool IfSafe(int need[process][num], int allocation[process][num], int availabe[num])
{
	int work[num] = { 0 };
	int finish[process] = { 0 };
	queue<int> q_pos;
	for (int i = 0; i < process; i++)
		q_pos.push(i);
	for (int i = 0; i < num; i++)
		work[i] = availabe[i];
	int temp = 0;//判断循环次数，避免死循环
	while (!q_pos.empty()) {
		int p = q_pos.front();
		q_pos.pop();
		temp++;
		if (compare(need[p], work)) {
			add(work, allocation[p]);
			finish[p] = true;
			que_pro.push(p);
			temp = 0;
		}
		else {
			if (temp > process) {
				clear(que_pro);//清空安全序列
				break;//若循环次数大于进程数，跳出循环
			}
			q_pos.push(p);
		}
	}
	for (int i = 0; i < process; i++)
		if (!finish[i])
			return false;
	return true;
}

bool Banker(int* request, int* need, int* available, int* allocation)
{
	if (!compare(request, need)) {
		cout << "所请求资源大于其最大需求值!" << endl;
		return false;
	}
	else if (!compare(request, available)) {
		cout << "尚无足够资源!" << endl;
		return false;
	}
	cha(available, request);
	add(allocation, request);
	cha(need, request);
	return true;
}

void Print(int* request, int* need, int* allocation, int* available, int temp)
{
	cout << "-------------------------------------" << endl;
	cout << "P" << temp << "进程请求资源:";
	for (int i = 0; i < num; i++)
		cout << request[i] << " ";
	cout << endl;
	cout << "P" << temp << "进程已分配资源:";
	for (int i = 0; i < num; i++)
		cout << allocation[i] << " ";
	cout << endl;
	cout << "P" << temp << "进程需要资源:";
	for (int i = 0; i < num; i++)
		cout << need[i] << " ";
	cout << endl;
	cout << "尚可利用资源:";
	for (int i = 0; i < num; i++)
		cout << available[i] << " ";
	cout << endl;
	cout << "-------------------------------------" << endl;
}
