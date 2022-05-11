#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
using namespace std;


int  main()
{
	cout << "输入两个数：";
	//如C73  表示7个里面选3个的情况总数
	int m, n;
	while (cin >> m >> n)
	{
		long long up = 1;
		long long down = 1;
		int t_m = m;
		int times = n;
		while (times--)
		{
			up *= t_m;
			t_m--;
		}
		for (int i = 1; i <= n; i++)
		{
			down *= i;
		}
		cout << up / down << endl;
	}

	return 0;
}






