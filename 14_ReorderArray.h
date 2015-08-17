#pragma	once
#include <iostream>
using namespace std;

// ====================方法一====================
//【两指针移动并交换数据】
//int *pData,int length表示数组,用指针来完成任务
void ReorderOddEven_1(int *pData,int length)
{
	if (pData==NULL || length==0)
		return;
	
	int *pBegin=pData;
	int *pEnd=pData+length-1;

	while(pBegin<pEnd)
	{
		//指针移动pBegin++，判断条件：所指值为奇
		while (pBegin<pEnd && (*pBegin)&1)
			pBegin++;
		while (pBegin<pEnd && (*pEnd)&1==0)
			pEnd++;

		//指针交换顺序
		if (pBegin<pEnd)
		{
			int temp=*pBegin;
			*pBegin=*pEnd;
			*pEnd=temp;
		}
	}
}

// ====================方法二====================

//回调函数的实现代码，调用Reorder()函数来调用回调函数
void ReorderOddEven_2(int *pData,int length)
{
	Reorder(pData,length,isEven);
}

//bool (*func)(int)用函数指针来调用回调函数，回调函数将函数指针放入到调用的函数参数中去，然后调用回调函数
void Reorder(int *pData,int length,bool (*func)(int))
{
	if (pData==NULL || length==0)
		return;

	int *pBegin=pData;
	int *pEnd=pData+length-1;

	while(pBegin<pEnd)
	{
		//指针移动pBegin++，判断条件：所指值为奇
		while (pBegin<pEnd && (*pBegin)&1)
			pBegin++;
		while (pBegin<pEnd && (*pEnd)&1==0)
			pEnd++;

		//指针交换顺序
		if (pBegin<pEnd)
		{
			int temp=*pBegin;
			*pBegin=*pEnd;
			*pEnd=temp;
		}
	}
}

//bool isEven(int n)就是回调函数
bool isEven(int n)
{
	return (n & 1)==0;
}