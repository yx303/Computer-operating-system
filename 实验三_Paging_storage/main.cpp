#include "Page.h"

int main() {
	vector<PCB> process;
	string name;
	while (true) {
		PCB p = creat_pcb();
		if (p.get_name() != "")
			process.push_back(p);
		else if (p.get_name() == "") {
			cout << "���޸���ռ䣬���̴���ʧ�ܣ�" << endl;
			break;
		}
		if (process.size() == 12) break;
	}
	cout << "���̴�����ɣ�����" << process.size() << "������!" << endl;
	cout << "������" << " " << "����ռ�" << endl;
	for (auto i = process.begin(); i != process.end(); i++) {
		cout.width(5);
		cout << i->get_name() << " " ;
		cout.width(8);
		cout << i->get_size() << endl;
	}
		
	cout << "λʾͼ:" << endl;
	show_wei();
	cout << endl;
	for (auto i = process.begin(); i != process.end(); i++)
		i->allo();
	cout << "�������!" << endl;
	cout << "��ӡҳ��:" << endl;
	for (auto i = process.begin(); i != process.end(); i++)
		i->show();
	cout << "λʾͼ:" << endl;
	show_wei();
	cout << endl;
	cout << "ɾ��������Ϊ:" << (process.begin() + 4)->get_name() << "�Ľ��̣����ͷ���ռ�õ������!" << endl;
	(process.begin() + 4)->show();
	(process.begin() + 4)->del();
	process.erase(process.begin() + 4);
	cout << "λʾͼ:" << endl;
	show_wei();
	cout << endl;
	while (true) {
		PCB p = creat_pcb();
		if (p.get_name() != "") {
			process.push_back(p);
			break;
		}
	}
	cout << "�´���һ��������Ϊ:" << (process.end()-1)->get_name() << " ����ռ��СΪ:" << (process.end() - 1)->get_size() << " �Ľ���!" << endl;
	cout << "Ϊ�����ռ�:" << endl;
	(process.end() - 1)->allo();
	(process.end() - 1)->show();
	cout << "λʾͼ:" << endl;
	show_wei();
	return 0;
}