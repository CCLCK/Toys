#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
#include <chrono>
using namespace std;

void test1()
{
	/*auto start = chrono::high_resolution_clock::now();
	unordered_map<int,int>um;
	um.insert(make_pair(1, 1));
	um.insert(make_pair(3, 1));
	um.insert(make_pair(2, 1));
	auto elapsed = chrono::high_resolution_clock::now() - start;
	long long microseconds = chrono::duration_cast<std::chrono::microseconds>(elapsed).count();*/
	//cout << microseconds << endl;

	//��Ҫ��ĺ����ŵ����Ｔ�� 
}

int CalTime(void (*p)())//����һ����ʽΪ void func������ʽ�ĺ���
//���غ���ָ��ָ��ĺ���������ʱ��
{
	auto start = std::chrono::high_resolution_clock::now();
	*p;
	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	long long microseconds = chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
	//duration_cast��ת�����͵�
	return microseconds;
}

int main()
{
	cout << CalTime(test1) << endl;
	return 0;
}

