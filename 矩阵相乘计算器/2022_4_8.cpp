#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include <vector>
#include <iomanip>
using namespace std;




int main()
{
	//首先确定需要三个矩阵 第一个矩阵a*b 第二个m*n 第三个a*n放结果
	int a, b;
	cout << "请输入第一个矩阵的行和列->";
	cin >> a >> b;
	cout << "请输入第一个矩阵的具体数据->" << endl;
	vector<vector<int>>v1(a, vector<int>(b));
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cin >> v1[i][j];
		}
	}
	int m, n;
	cout << "请输入第二个矩阵的行和列->";
	cin >> m >> n;
	cout << "请输入第二个矩阵的具体数据->"<<endl;
	vector<vector<int>>v2(m,vector<int>(n)) ;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v2[i][j];
		}
	}
	vector<vector<int>>v3(a, vector<int>(n));
	if (b != m)
	{
		cout << "输入不符合要求" << endl;
		system("pause");
		return 0;
	}
	
	for (int i = 0; i < a; i++)//枚举某一行的每个数
	{
		for (int j = 0; j < n; j++)//枚举某一列的每个数
		{
			for (int k = 0; k < b; k++)//每一个数的计算结果
			{
				v3[i][j] += (v1[i][k] * v2[k][j]);
			}
		}
	}
	cout << "----------计算结果----------" << endl;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d", v3[i][j]);
		}
		cout << endl;
	}
	system("pause");
	return 0;
}





