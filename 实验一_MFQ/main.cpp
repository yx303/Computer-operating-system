#include"MFQ.h"
#include<fstream>

int main() {
	Queue P[max];
	PCB A = { "A",0,10,10,0,0,0.0 };
	PCB B = { "B",4,60,60,0,0,0.0 };
	PCB C = { "C",5,6,6,0,0,0.0 };
	PCB D = { "D",6,5,5,0,0,0.0 };
	PCB E = { "E",7,3,3,0,0,0.0 };
	PCB F = { "F",10,12,12,0,0,0.0 };
	queue<PCB> list, result;
	list.push(A);
	list.push(B);
	list.push(C);
	list.push(D);
	list.push(E);
	list.push(F);
	P[0].time = 1;
	for (int i = 1; i < max; i++)
		P[i].time = 2 * P[i - 1].time;
	result = ProcessExecute(P, list);
	PCB p;
	ofstream out;
	out.open("result.txt", ios::out);
	if (!out) cout << "文件打开失败!" << endl;
	out << "进程名" << " " << "服务时间" << " " << "到达时间" << "   " << "完成时间" << "  " << "周转时间" << "   " << "带权周转时间" << endl;
	cout << "进程名" << " " << "服务时间" << " " << "到达时间" << " " << "完成时间" << " " << "周转时间" << " " << "带权周转时间" << endl;
	while (!result.empty()) {
		p = result.front();
		p.turn_weight_time = (double)p.turnaround_time / p.need_time;
		out << p.name << "\t" << p.need_time << "\t" << p.arrive_time << "\t" << p.finish_time << "\t" << p.turnaround_time << "\t" << fixed << setprecision(2) << p.turn_weight_time << endl;
		Print(result.front());
		result.pop();
	}
	return 0;
}