#define _CRT_SECURE_NO_WARNINGS 1

#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <corecrt_wprocess.h>
using namespace std;
string ans;//��¼������

int main()
{
	float n;
	cout << "����һ����������";
	cin >> n;
	if (n >= 0)
	{
		ans += '0';
	}
	else
	{
		ans += '1';
	}
	string res(ans);//��¼�洢���
	int ineteger=(int)n;
	float decimal=n-ineteger;
	//�������ɶ����Ƶõ�ָ��
	int tmp = ineteger;
	string str_tmp;//��������Ķ�����
	int cnt = 0;
	ans += "           ";
	while (tmp)
	{
		if (tmp & 1)//���һλ��1
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
	int index = cnt + 127-1;//ָ�� ���������ת�ɶ�����
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

	//��ʼ����С������
	res += ' '; 
	res += ans.substr(3);//���������ֵ���Ч��λ�ù���

	ans += "                ";
	int sub = ans.size();//��¼�˿�λ�� ����׷��

	times = 23-cnt+1;//cntΪ����λ�� cnt-1ΪҪ�ŵ�λ�� һ����23λ
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
			ans += '1';//׷��һ��1�����ȫ��0
			decimal = 0;
		}
	}
	res += ans.substr(sub);
	_wsystem(L"color 0a");
	_wsystem(L"color 0b");
	cout << "����λ"<<setw(20) << "�������ֵĶ�����"<<setw(25)<<"С�����ֵĶ�����" << endl;
	cout << ans << endl;
	cout <<"---------------------" << endl;
	cout << "����λ" << setw(15) << "ָ��" << setw(25) << "��Ч����" << endl;
	cout << res << endl;
	
	return 0;
}






