#pragma once
#include <iostream>
using namespace std;

//˼·:��n&flag���жϣ�n&(n-1)����<</>>��ȡ��*��/���Ч��
//ע�⣺
//1����if(n)ȡ��if(n��=0)
//2����if(n&flag)ȡ��if ((n&flag)==flag)

//ע���������
//0x80000000��1000 000 FF FF FF 32λϵͳ���λΪ1������
//0x7FFFFFFF���int������
//0xFFFFFFFF���ɱ�ʾ����

//BugSolution���㷨�ڸ�������bug����������ѭ��

int NumberOf1_Solution1(int n)
{
	int count=0;
	int flag=1;
	while (flag)
	{
		int t=n&flag;

		if (n&flag)
		{
			++count;
		}
		flag=flag<<1;
	}
	return count;
}

int NumberOf1_Solution2(int n)
{
	int count=0;
	while (n)
	{
		n=n&(n-1);
		++count;
	}
	return count;
}

int NumberOf1_BugSolution(int n)
{
	int count=0;
	while (n)
	{
		if (n&1)
		{
			++count;
		}
		n=n>>1;
	}
	return count;
}

void Test(int number)
{
	int actual=NumberOf1_Solution1(number);
	cout<<number<<"\t"<<actual<<endl;

	actual = NumberOf1_Solution2(number);
	cout<<number<<"\t"<<actual<<endl<<endl;

	//actual = NumberOf1_BugSolution(number);
	//cout<<number<<"\t"<<actual<<endl<<endl;
}

void Test1()
{
	Test(0);
	Test(1);
	Test(10);
	Test(0x7FFFFFFF);	//31
	Test(0xFFFFFFFF);   //32(����)
	Test(0x80000000);	//1
	Test(0xFF);
}