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

	//把要测的函数放到这里即可 
}

int CalTime(void (*p)())//接收一个格式为 void func（）格式的函数
//返回函数指针指向的函数的运行时间
{
	auto start = std::chrono::high_resolution_clock::now();
	*p;
	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	long long microseconds = chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
	//duration_cast是转化类型的
	return microseconds;
}

int main()
{
	cout << CalTime(test1) << endl;
	return 0;
}

