#pragma once
#ifndef _BANKER_H_
#define _BANKER_H_
#include<iostream>
#include<queue>
using namespace std;
#define num 3//��Դ��Ŀ
#define process 5//������Ŀ

extern queue<int> que_pro;//��Ž����±�

void clear(queue<int> q);
bool compare(int* need, int* work);//��need�и�Ԫ�ض�ӦС��work�и�Ԫ�أ�����true
void add(int* work, int* allo);
void cha(int* avi, int* request);
bool IfSafe(int need[process][num], int allocation[process][num], int available[num]);//��ȫ���㷨
bool Banker(int* request, int* need, int* available, int* allocation);
void Print(int* request, int* need, int* allocation, int* available, int temp);

#endif//_BANKER_H_