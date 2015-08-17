#pragma once
#include <iostream>
#include <stack>
#include "List.h"
//�������͵�test��1��12345���У�2������һ��1��3��NULL������

//�ݹ�ʱ��ͼ���ֲ������ͺ���ջʹ�������
//pNode���ָ��NULL��m_pData=5
//ͨ��if���жϵݹ���ֹ����������while
void PrintReverseList_Recursively(ListNode* pHead)
{
	if(pHead!=NULL)
	{
		//ListNode* pNode=pHead;
		if(pHead->m_pNext!=NULL)
		{
			PrintReverseList_Recursively(pHead->m_pNext);
		}
		cout<<pHead->m_nData<<"\t";
	}
}

//��stackʵ��ջ
void PrintReverseList_Iteratively(ListNode* pHead)
{
	if(pHead!=NULL)
	{
		stack<ListNode*> sList;
		ListNode* pNode=pHead;
		while(pNode!=NULL)
		{
			sList.push(pNode);
			pNode=pNode->m_pNext;
		}
		while(!sList.empty())
		{
			pNode=sList.top();
			sList.pop();
			cout<<pNode->m_nData<<"\t";
		}
	}
}

void Test1()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	PrintList(pNode1);
	//PrintReverseList(pNode1);
	PrintReverseList_Recursively(pNode1);
	cout<<endl;
	PrintReverseList_Iteratively(pNode1);

	DestroyList(pNode1);
}

