#include "Banker.h"
using namespace std;

int main() {
	int available[num] = { 3,3,2 };//��������Դ����
	int allocation[process][num] = { {0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2} };//�������
	int need[process][num] = { {7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1} };//�������
	int available_1[num];
	int allocation_1[process][num];
	int need_1[process][num];
	memcpy(available_1, available, sizeof(available));
	memcpy(allocation_1, allocation, sizeof(allocation));
	memcpy(need_1, need, sizeof(need));
	if (IfSafe(need, allocation, available)) {
		cout << "��ʼ״̬��ȫ" << endl;
		cout << "��ȫ����Ϊ��";
		while (!que_pro.empty()) {
			cout << "P" << que_pro.front() << " ";
			que_pro.pop();
		}
		cout << endl;
		string choice;
		cout << "-------------------------------------" << endl;
		cout << "�Ƿ���Ҫ������Դ��y/n:";
		cin >> choice;
		cout << "-------------------------------------" << endl;
		while(true) {
			if (choice == "y") {
				int request[num];
				int temp;//���̺�
				cout << "��������������Դ�Ľ��̺�:";
				cin >> temp;
				cout << "������������������Դ��Ӧ��������";
				for (int i = 0; i < num; i++)
					cin >> request[i];
				Print(request, need_1[temp], allocation_1[temp], available_1, temp);
				if (Banker(request, need_1[temp], available_1, allocation_1[temp])) {
					cout << "����ʱ�ٶ�����ΪP" << temp << "������Դ" << endl;
					if (IfSafe(need_1, allocation_1, available_1)) {
						memcpy(available, available_1, sizeof(available_1));
						memcpy(allocation, allocation_1, sizeof(allocation_1));
						memcpy(need, need_1, sizeof(need_1));
						cout << "-------------------------------------" << endl;
						cout << "�����״̬��ȫ,����ΪP" << temp << "������Դ!" << endl;
						cout << "��ȫ����Ϊ��";
						while (!que_pro.empty()) {
							cout << "P" << que_pro.front() << " ";
							que_pro.pop();
						}
						cout << endl;
					}
					else {
						memcpy(available_1, available, sizeof(available));
						memcpy(allocation_1, allocation, sizeof(allocation));
						memcpy(need_1, need, sizeof(need));
						cout << "-------------------------------------" << endl;
						cout << "�����״̬����ȫ, ��P" << temp << "�ȴ�!" << endl;
					}
				}
				else {
					memcpy(available_1, available, sizeof(available));
					memcpy(allocation_1, allocation, sizeof(allocation));
					memcpy(need_1, need, sizeof(need));
					cout << "-------------------------------------" << endl;
					cout << "����ʱ���ܸ�P" << temp << "������Դ!" << endl;
				}
			}
			else if (choice == "n") break;
			cout << "-------------------------------------" << endl;
			cout << "�Ƿ���Ҫ������Դ��y/n:";
			cin >> choice;
			cout << "-------------------------------------" << endl;
		}
	}
	else
		cout << "��ʼ״̬����ȫ��" << endl;
	return 0;
}