#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include <vector>
#include <iomanip>
using namespace std;




int main()
{
	//����ȷ����Ҫ�������� ��һ������a*b �ڶ���m*n ������a*n�Ž��
	int a, b;
	cout << "�������һ��������к���->";
	cin >> a >> b;
	cout << "�������һ������ľ�������->" << endl;
	vector<vector<int>>v1(a, vector<int>(b));
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cin >> v1[i][j];
		}
	}
	int m, n;
	cout << "������ڶ���������к���->";
	cin >> m >> n;
	cout << "������ڶ�������ľ�������->"<<endl;
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
		cout << "���벻����Ҫ��" << endl;
		system("pause");
		return 0;
	}
	
	for (int i = 0; i < a; i++)//ö��ĳһ�е�ÿ����
	{
		for (int j = 0; j < n; j++)//ö��ĳһ�е�ÿ����
		{
			for (int k = 0; k < b; k++)//ÿһ�����ļ�����
			{
				v3[i][j] += (v1[i][k] * v2[k][j]);
			}
		}
	}
	cout << "----------������----------" << endl;
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





