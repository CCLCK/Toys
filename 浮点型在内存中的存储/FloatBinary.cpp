#define _CRT_SECURE_NO_WARNINGS 1

#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <corecrt_wprocess.h>
using namespace std;
string ans;//记录二进制

int main()
{
	float n;
	cout << "输入一个浮点数：";
	cin >> n;
	if (n >= 0)
	{
		ans += '0';
	}
	else
	{
		ans += '1';
	}
	string res(ans);//记录存储结果
	int ineteger=(int)n;
	float decimal=n-ineteger;
	//整数化成二进制得到指数
	int tmp = ineteger;
	string str_tmp;//存放整数的二进制
	int cnt = 0;
	ans += "           ";
	while (tmp)
	{
		if (tmp & 1)//最后一位是1
		{
			str_tmp += '1';
			cnt++;
		}
		else
		{
			str_tmp += '0';
			cnt++;
		}
		tmp >>= 1;
	}
	reverse(str_tmp.begin(), str_tmp.end());
	ans += str_tmp;
	int index = cnt + 127-1;//指数 把这个数字转成二进制
	int times = 8;
	res += "                ";
	while (times)
	{
		times--;
		if ((index>>times)&1)
		{
			res += '1';
		}
		else
		{
			res += '0';
		}
	}

	//开始处理小数部分
	res += ' '; 
	res += ans.substr(3);//把整数部分的有效数位拿过来

	ans += "                ";
	int sub = ans.size();//记录此刻位置 用于追加

	times = 23-cnt+1;//cnt为整数位数 cnt-1为要放的位数 一共放23位
	while (times--)
	{
		decimal *= 2;
		if (decimal > 1)
		{
			ans += '1';			
			decimal -= 1;
		}
		else if(decimal<1)
		{
			ans += '0';
		}
		else
		{
			ans += '1';//追加一个1后后面全是0
			decimal = 0;
		}
	}
	res += ans.substr(sub);
	_wsystem(L"color 0a");
	_wsystem(L"color 0b");
	cout << "符号位"<<setw(20) << "整数部分的二进制"<<setw(25)<<"小数部分的二进制" << endl;
	cout << ans << endl;
	cout <<"---------------------" << endl;
	cout << "符号位" << setw(15) << "指数" << setw(25) << "有效数字" << endl;
	cout << res << endl;
	
	return 0;
}






