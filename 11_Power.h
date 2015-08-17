#pragma once
#include <iostream>
using namespace std;

//考察点：考虑指数是负数的情况；当传入参数为int时，均要考虑为负的情况
//这次用全局函数来错误检查，优点是方便使用错误结果；缺点是会忘记检查全局变量
//在实现正数的n次方时，单独写一函数进行；层次明确

//出错点&&优化：
//double是否为0：abs(base)<=0.000001
//正数用 unsigned int表示
//求a的n次方的三处优化方式，见书，p93

//函数高效：求a的n次方用函数递归;demo实现
//测试用例：底数和指数分别用正数，负数，0；0的0次无意义，单独说明

bool g_InvalidInput=false;
double PowerWithUnsignedExponent(double base, unsigned int exponent);
double PowerWithUnsignedExponent_best(double base, unsigned int exponent);

double Power(double base,int exponent)
{
	if (abs(base)<=0.000001 && exponent<0)
	{
		g_InvalidInput=true;
		//cout<<"intput error"<<endl;
		return 0;
	}

	unsigned int absExponent=(unsigned int)abs(exponent);
	double result=PowerWithUnsignedExponent_best(base,absExponent);
	if (exponent<0)
		result=1.0/result;

	return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	double result=1.0;
	while (exponent--)
	{
		result*=base;
	}
	return result;
}

double PowerWithUnsignedExponent_best(double base, unsigned int exponent)
{
	if(exponent == 0)
		return 1;
	if(exponent == 1)
		return base;

	double result=PowerWithUnsignedExponent(base, exponent >> 1);
	result*=result;
	if (exponent&1)
		result*=base;
	
	return result;
}

void Test()
{
	cout<<Power(2,-2)<<endl;
	cout<<Power(2,2)<<endl;
	cout<<Power(2,0)<<endl<<endl;

	cout<<Power(0,3)<<endl;
	cout<<Power(0,-3)<<endl<<endl;
	
	cout<<Power(-2,3)<<endl;
	cout<<Power(-2,-3)<<endl;
	cout<<Power(-2,0)<<endl;

}