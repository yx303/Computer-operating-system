#pragma once
#ifndef _FIRST_H_
#define _FIRST_H_
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;
#define max 5

extern int all_time;
struct PCB {
	string name;
	int arrive_time = 0;
	int need_time = 0;
	int left_time = 0;
	int finish_time = 0;
	int turnaround_time = 0;
	double turn_weight_time = 0.0;
};

struct Queue {
	queue<PCB> process;
	int time = 0;//时间片
};

void Print(PCB &p);//输出进程
queue<PCB> ProcessExecute(Queue* q, queue<PCB> &list);//执行进程
void Round(Queue* q, int i, queue<PCB>& list, queue<PCB>& temp);
void Without(Queue* q, int i, PCB& p, queue<PCB>& temp);
void Left(Queue* q, int i, int time, PCB& p, queue<PCB>& temp);

#endif//_FIRST_H_