#pragma once
#include <iostream>
using namespace std;

//����㣺����ָ���Ǹ�������������������Ϊintʱ����Ҫ����Ϊ�������
//�����ȫ�ֺ����������飬�ŵ��Ƿ���ʹ�ô�������ȱ���ǻ����Ǽ��ȫ�ֱ���
//��ʵ��������n�η�ʱ������дһ�������У������ȷ

//�����&&�Ż���
//double�Ƿ�Ϊ0��abs(base)<=0.000001
//������ unsigned int��ʾ
//��a��n�η��������Ż���ʽ�����飬p93

//������Ч����a��n�η��ú����ݹ�;demoʵ��
//����������������ָ���ֱ���������������0��0��0�������壬����˵��

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