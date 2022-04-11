#pragma once
#ifndef _PAGE_H_
#define _PAGE_H_
#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;
#define max 100//物理块个数
#define page 1024//页面大小，单位B
#define m 512
#define n 5000
extern bool Physical[max];
extern bool al[26];

struct Page_Table {
	int page_num;//页号
	int block_num;//块号
};

class PCB {
private:
	string name;
	int size;
	bool ifallo = false;
	vector<Page_Table> page_item;
public:
	PCB(string n1, int s);
	void allo();//分配
	void show();//打印页表
	void del();//回收
	string get_name();//获取进程名
	int get_size();
};

int Number();//返回已用物理块个数
PCB creat_pcb();//创建进程
void show_wei();//打印位示图

#endif//_PAGE_H_ 