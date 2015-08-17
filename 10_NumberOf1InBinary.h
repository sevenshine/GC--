#pragma once
#include <iostream>
using namespace std;

//思路:用n&flag来判断；n&(n-1)；用<</>>来取代*、/提高效率
//注意：
//1、用if(n)取代if(n！=0)
//2、用if(n&flag)取代if ((n&flag)==flag)

//注意测试用例
//0x80000000：1000 000 FF FF FF 32位系统最高位为1，负数
//0x7FFFFFFF最大int正整数
//0xFFFFFFFF最大可表示负数

//BugSolution中算法在负数中有bug，陷入无限循环

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
	Test(0xFFFFFFFF);   //32(负数)
	Test(0x80000000);	//1
	Test(0xFF);
}