#pragma once
#ifndef _PAGE_H_
#define _PAGE_H_
#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;
#define max 100//��������
#define page 1024//ҳ���С����λB
#define m 512
#define n 5000
extern bool Physical[max];
extern bool al[26];

struct Page_Table {
	int page_num;//ҳ��
	int block_num;//���
};

class PCB {
private:
	string name;
	int size;
	bool ifallo = false;
	vector<Page_Table> page_item;
public:
	PCB(string n1, int s);
	void allo();//����
	void show();//��ӡҳ��
	void del();//����
	string get_name();//��ȡ������
	int get_size();
};

int Number();//����������������
PCB creat_pcb();//��������
void show_wei();//��ӡλʾͼ

#endif//_PAGE_H_ 