#pragma once
#include <iostream>
using namespace std;

//1、斐波那契数列最常见为递归算法，但是算法效率太低，时间复杂度为n的指数次
//2、故采用循环方式，时间复杂度为O(n)，最简单方式为从下往上计算，然后通过A、B数据保存前两项
//3、有一个数学公式可以写出O(logn)的算法，略

//测试用例：功能测试（4,6,10），边界测试（0,1,2），性能测试（100,1000）

long long Fibonacci(unsigned int n)
{
	if (n<=0)
		return 0;
	else if (n==1)
		return 1;
	else
		return Fibonacci(n-1)+Fibonacci(n-2);
}	

long long Fibonacci1(unsigned int n)
{
	//用数组来代替if判断，展现优美代码风格
	int result[2]={0,1};
	if (n<2)
		return result[n];

	long long fibA=0;
	long long fibB=1;
	long long fib;
	for (int i=0;i<n;i++)
	{
		fib=fibA+fibB;
		fibA=fibB;
		fibB=fib;
	}
	return fib;
}