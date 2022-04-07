#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int GetRONumber(vector<int>&v)//得到一个序列的逆序数
{
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int cnt = 0;
		bool f = 0;
		for (int j = i+1; j < v.size(); j++)
		{
			if (v[j] < v[i])
			{
				cnt++;
			}
			if (v[j-1]>v[j])//存在后面的数小于前面的数，序列不是整体升序
			{
				f = 1;
			}
		}
		if (f==0)
		{
			break;
		}
		sum += cnt;
	}
	return sum;
}
//int main()
//测试逆序数模块
//{
//	vector<int>v;
//	v.push_back(3);
//	v.push_back(2);
//	v.push_back(5);
//	v.push_back(1);
//	v.push_back(4);
//	//sort(v.begin(), v.end(),greater<int>());
//	cout << GetRONumber(v) << endl;
//	//next_permutation(v.begin(), v.end());
//	//cout << GetRONumber(v) << endl;
//	//next_permutation(v.begin(), v.end());
//	//cout << GetRONumber(v) << endl;
//
//	return 0;
//}
int a[100][100];
vector<int>v;
int main()
{
	int n;
	cout << "输入n阶行列式的n->";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}
	cout << "请输入具体数据："<<endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	int ans = 0;
	do
	{
		int index = 1;
		int mul = 1;
		for (auto e : v)
		{
			mul *= a[index][e];
			index++;
		}
		if (GetRONumber(v) % 2 == 0)
		{
			ans += mul;
		}
		else
		{
			ans -= mul;
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
	system("pause");
	return 0;
}



