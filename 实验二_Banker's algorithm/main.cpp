#include "Banker.h"
using namespace std;

int main() {
	int available[num] = { 3,3,2 };//可利用资源向量
	int allocation[process][num] = { {0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2} };//分配矩阵
	int need[process][num] = { {7,4,3},{1,2,2},{6,0,0},{0,1,1},{4,3,1} };//需求矩阵
	int available_1[num];
	int allocation_1[process][num];
	int need_1[process][num];
	memcpy(available_1, available, sizeof(available));
	memcpy(allocation_1, allocation, sizeof(allocation));
	memcpy(need_1, need, sizeof(need));
	if (IfSafe(need, allocation, available)) {
		cout << "初始状态安全" << endl;
		cout << "安全序列为：";
		while (!que_pro.empty()) {
			cout << "P" << que_pro.front() << " ";
			que_pro.pop();
		}
		cout << endl;
		string choice;
		cout << "-------------------------------------" << endl;
		cout << "是否需要请求资源，y/n:";
		cin >> choice;
		cout << "-------------------------------------" << endl;
		while(true) {
			if (choice == "y") {
				int request[num];
				int temp;//进程号
				cout << "请输入所请求资源的进程号:";
				cin >> temp;
				cout << "请依次输入所请求资源对应的数量：";
				for (int i = 0; i < num; i++)
					cin >> request[i];
				Print(request, need_1[temp], allocation_1[temp], available_1, temp);
				if (Banker(request, need_1[temp], available_1, allocation_1[temp])) {
					cout << "可暂时假定可以为P" << temp << "分配资源" << endl;
					if (IfSafe(need_1, allocation_1, available_1)) {
						memcpy(available, available_1, sizeof(available_1));
						memcpy(allocation, allocation_1, sizeof(allocation_1));
						memcpy(need, need_1, sizeof(need_1));
						cout << "-------------------------------------" << endl;
						cout << "分配后状态安全,可以为P" << temp << "分配资源!" << endl;
						cout << "安全序列为：";
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
						cout << "分配后状态不安全, 让P" << temp << "等待!" << endl;
					}
				}
				else {
					memcpy(available_1, available, sizeof(available));
					memcpy(allocation_1, allocation, sizeof(allocation));
					memcpy(need_1, need, sizeof(need));
					cout << "-------------------------------------" << endl;
					cout << "故暂时不能给P" << temp << "分配资源!" << endl;
				}
			}
			else if (choice == "n") break;
			cout << "-------------------------------------" << endl;
			cout << "是否需要请求资源，y/n:";
			cin >> choice;
			cout << "-------------------------------------" << endl;
		}
	}
	else
		cout << "初始状态不安全！" << endl;
	return 0;
}