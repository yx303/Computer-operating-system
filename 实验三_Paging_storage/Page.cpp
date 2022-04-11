#include "Page.h"

bool Physical[max] = { false };
bool al[26] = { false };

PCB::PCB(string n1, int s)
{
	name = n1;
	size = s;
}

void PCB::allo()
{
	if (ifallo) return;
	Page_Table p = { 0,0 };
	int j;
	for (int i = 0; i < size / page + 1; i++) {
		p.page_num = i;
		j = 0;
		while (true)
		{
			if (!Physical[j]) {
				p.block_num = j;
				Physical[j] = true;
				break;
			}
			j++;
		}
		page_item.push_back(p);
	}
	ifallo = true;
}

void PCB::show()
{
	cout << "进程名：" << name << " " << "所需空间:" << size << endl;
	cout << "页号" << " " << "块号" << endl;
	for (auto i = page_item.begin(); i != page_item.end(); i++) {
		cout.width(3);
		cout << i->page_num << " ";
		cout.width(4);
		cout << i->block_num << endl;
	}
	cout << endl;
}

void PCB::del()
{
	for (auto i = page_item.begin(); i != page_item.end(); i++)
		Physical[i->block_num] = false;
	al[name[0] - 'A'] = false;
}

string PCB::get_name()
{
	return name;
}

int PCB::get_size()
{
	return size;
}

int Number()
{
	int num = 0;
	for (int i = 0; i < max; i++)
		if (Physical[i])
			num++;
	return num;
}

PCB creat_pcb()
{
	int s, used, randnum;
	string name;
	s = rand() % (n - m + 1) + m;
	while (true) {
		randnum = rand() % 26;
		if (!al[randnum]) {
			name = 'A' + randnum;
			al[randnum] = true;
			break;
		}
	}
	used = Number();
	if (used + s / page + 1 > max)
		name = "";
	PCB p(name, s);
	return p;
}

void show_wei()
{
	for (int i = 0; i < max; i++) {
		cout.width(2);
		cout << i << " " << Physical[i] << "\t";
		if (i % 5 == 4) cout << endl;
	}
}
