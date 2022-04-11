#pragma once
#ifndef _BANKER_H_
#define _BANKER_H_
#include<iostream>
#include<queue>
using namespace std;
#define num 3//资源数目
#define process 5//进程数目

extern queue<int> que_pro;//存放进程下标

void clear(queue<int> q);
bool compare(int* need, int* work);//若need中各元素对应小于work中各元素，返回true
void add(int* work, int* allo);
void cha(int* avi, int* request);
bool IfSafe(int need[process][num], int allocation[process][num], int available[num]);//安全性算法
bool Banker(int* request, int* need, int* available, int* allocation);
void Print(int* request, int* need, int* allocation, int* available, int temp);

#endif//_BANKER_H_