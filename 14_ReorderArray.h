#pragma	once
#include <iostream>
using namespace std;

// ====================����һ====================
//����ָ���ƶ����������ݡ�
//int *pData,int length��ʾ����,��ָ�����������
void ReorderOddEven_1(int *pData,int length)
{
	if (pData==NULL || length==0)
		return;
	
	int *pBegin=pData;
	int *pEnd=pData+length-1;

	while(pBegin<pEnd)
	{
		//ָ���ƶ�pBegin++���ж���������ֵָΪ��
		while (pBegin<pEnd && (*pBegin)&1)
			pBegin++;
		while (pBegin<pEnd && (*pEnd)&1==0)
			pEnd++;

		//ָ�뽻��˳��
		if (pBegin<pEnd)
		{
			int temp=*pBegin;
			*pBegin=*pEnd;
			*pEnd=temp;
		}
	}
}

// ====================������====================

//�ص�������ʵ�ִ��룬����Reorder()���������ûص�����
void ReorderOddEven_2(int *pData,int length)
{
	Reorder(pData,length,isEven);
}

//bool (*func)(int)�ú���ָ�������ûص��������ص�����������ָ����뵽���õĺ���������ȥ��Ȼ����ûص�����
void Reorder(int *pData,int length,bool (*func)(int))
{
	if (pData==NULL || length==0)
		return;

	int *pBegin=pData;
	int *pEnd=pData+length-1;

	while(pBegin<pEnd)
	{
		//ָ���ƶ�pBegin++���ж���������ֵָΪ��
		while (pBegin<pEnd && (*pBegin)&1)
			pBegin++;
		while (pBegin<pEnd && (*pEnd)&1==0)
			pEnd++;

		//ָ�뽻��˳��
		if (pBegin<pEnd)
		{
			int temp=*pBegin;
			*pBegin=*pEnd;
			*pEnd=temp;
		}
	}
}

//bool isEven(int n)���ǻص�����
bool isEven(int n)
{
	return (n & 1)==0;
}