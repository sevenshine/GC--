#pragma	once
#include <iostream>
#include "List.h"
using namespace std;

/* ����ת����ʵ����ѭ������ȵݹ������ */
//�ݹ�ʵ�֣�ע��ݹ�ʵ�ֵķ��أ�ͨ���������жϵݹ����ȷ�ԣ�eg��listΪ1,2����
ListNode* Reverse(ListNode* pHead, ListNode* pNode);
ListNode* ReverseList1(ListNode* pListHead)
{
	if (pListHead==NULL)
		return NULL;

	ListNode* pNode=pListHead;
	ListNode* pPrev=NULL;
	ListNode* pReverseHead=Reverse(pPrev, pNode);

	return pReverseHead;
}

ListNode* Reverse(ListNode* pPrev, ListNode* pNode)
{
	ListNode* pNext=pNode->m_pNext;
	pNode->m_pNext=pPrev;
	if (pNext==NULL)
		return pNode;
	return Reverse(pNode,pNext);
}

//1����pReverseHead����ʾ������
//2��ѭ�������жϣ�pNode!=NULL������pNext==NULL
//3����ͼ������ѭ�����̣���д���ؼ�����
ListNode* ReverseList2(ListNode* pListHead)
{
	ListNode* pReverseHead=NULL;
	ListNode* pNode=pListHead;
	ListNode* pPrev=NULL;
	
	while(pNode!=NULL)
	{
		ListNode* pNext=pNode->m_pNext;
		if (pNext==NULL)
			pReverseHead=pNode;

		pNode->m_pNext=pPrev;
		pPrev=pNode;
		pNode=pNext;
	}
	return pReverseHead;
}


void TestList()
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
	ListNode* p=ReverseList1(pNode1);
	PrintList(p);


	DestroyList(pNode1);
}