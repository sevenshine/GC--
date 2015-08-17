#pragma once
#include <iostream>
#include <set>
#include <vector>
#include "7_HeapSort.h"
using namespace std;

//【TopK】找出最大的k个数，使用最小堆
//1、伪代码h[k]表示最小堆，直接读入开始的k个数，然后逐个读入X比较
//2、将X插入到最小堆中
if (X>h[0])
{
	h[0]=X;	//替换最小堆根结点
	p=0;
	while (p<k)
	{
		//左子树
		q=2*p+1;
		if(q>=k)
			break;
		//判断插入左子树还是右子树
		if((q<K-1) && (h[q+1]<h))
			q=q+1;
		//向下调整
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





//【TopK】
//直接数组输入，然后调整；容器输入数据，采取队列的输入输出来给最小堆提供数据
//直接用STL实现TopK，有待补充
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


