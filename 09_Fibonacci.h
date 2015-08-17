#pragma once
#include <iostream>
using namespace std;

//1��쳲������������Ϊ�ݹ��㷨�������㷨Ч��̫�ͣ�ʱ�临�Ӷ�Ϊn��ָ����
//2���ʲ���ѭ����ʽ��ʱ�临�Ӷ�ΪO(n)����򵥷�ʽΪ�������ϼ��㣬Ȼ��ͨ��A��B���ݱ���ǰ����
//3����һ����ѧ��ʽ����д��O(logn)���㷨����

//�������������ܲ��ԣ�4,6,10�����߽���ԣ�0,1,2�������ܲ��ԣ�100,1000��

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
	//������������if�жϣ�չ������������
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