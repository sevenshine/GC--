#pragma once
#include <iostream>
#include <set>
#include <vector>
#include "7_HeapSort.h"
using namespace std;

//��TopK���ҳ�����k������ʹ����С��
//1��α����h[k]��ʾ��С�ѣ�ֱ�Ӷ��뿪ʼ��k������Ȼ���������X�Ƚ�
//2����X���뵽��С����
if (X>h[0])
{
	h[0]=X;	//�滻��С�Ѹ����
	p=0;
	while (p<k)
	{
		//������
		q=2*p+1;
		if(q>=k)
			break;
		//�жϲ�������������������
		if((q<K-1) && (h[q+1]<h))
			q=q+1;
		//���µ���
		if (h[q]<h[p])
		{
			t=h[p];
			h[p]=h[q];
			h[q]=t;
			p=q;
		}
		else
			break;
	}
}





//��TopK��
//ֱ���������룬Ȼ������������������ݣ���ȡ���е��������������С���ṩ����
//ֱ����STLʵ��TopK���д�����
void GetTopK(int data[], int n,int leastData[], int k)
{
	for (int i=0;i<k;i++)
	{
		leastData[i]=data[i];
	}

	MakeMinHeap(leastData,k);
	for (int i=k;i<n;i++)
	{
		if (data[i]<leastData[0])
		{
			MinHeapDeleteNumber(leastData,k);
			MinHeapAddNumber(leastData,k-1,data[i]);
		}
	}
}

// ====================Test====================
void PrintSort(int arr[],int length)
{
	for (int i=0;i<length;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void TestTopK()
{
	int data[]={64, 34, 25, 12, 22, 11, 90, 88, 23};
	int length=sizeof(data)/sizeof(data[0]);
	const int k=5;
	int leastData[k]={0};
	PrintSort(data,length);
	PrintSort(leastData,k);

	GetTopK(data,length,leastData,k);
	PrintSort(leastData,k);
}


