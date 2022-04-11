#include "Page.h"

int main() {
	vector<PCB> process;
	string name;
	while (true) {
		PCB p = creat_pcb();
		if (p.get_name() != "")
			process.push_back(p);
		else if (p.get_name() == "") {
			cout << "已无更多空间，进程创建失败！" << endl;
			break;
		}
		if (process.size() == 12) break;
	}
	cout << "进程创建完成，共有" << process.size() << "个进程!" << endl;
	cout << "进程名" << " " << "所需空间" << endl;
	for (auto i = process.begin(); i != process.end(); i++) {
		cout.width(5);
		cout << i->get_name() << " " ;
		cout.width(8);
		cout << i->get_size() << endl;
	}
		
	cout << "位示图:" << endl;
	show_wei();
	cout << endl;
	for (auto i = process.begin(); i != process.end(); i++)
		i->allo();
	cout << "分配完成!" << endl;
	cout << "打印页表:" << endl;
	for (auto i = process.begin(); i != process.end(); i++)
		i->show();
	cout << "位示图:" << endl;
	show_wei();
	cout << endl;
	cout << "删除进程名为:" << (process.begin() + 4)->get_name() << "的进程，并释放所占用的物理块!" << endl;
	(process.begin() + 4)->show();
	(process.begin() + 4)->del();
	process.erase(process.begin() + 4);
	cout << "位示图:" << endl;
	show_wei();
	cout << endl;
	while (true) {
		PCB p = creat_pcb();
		if (p.get_name() != "") {
			process.push_back(p);
			break;
		}
	}
	cout << "新创建一个进程名为:" << (process.end()-1)->get_name() << " 所需空间大小为:" << (process.end() - 1)->get_size() << " 的进程!" << endl;
	cout << "为其分配空间:" << endl;
	(process.end() - 1)->allo();
	(process.end() - 1)->show();
	cout << "位示图:" << endl;
	show_wei();
	return 0;
}