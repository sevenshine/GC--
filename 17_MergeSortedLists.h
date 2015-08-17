#pragma	once
#include <iostream>
#include "List.h"
using namespace std;

ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1==NULL)
		return pHead2;
	if (pHead2==NULL)
		return pHead1;
	ListNode* pHead=NULL;
	if (pHead1->m_nData < pHead2->m_nData)
	{
		pHead = pHead1;
		pHead->m_pNext = MergeList(pHead1->m_pNext, pHead2);
	}
	else
	{
		pHead = pHead2;
		pHead->m_pNext = MergeList(pHead1, pHead2->m_pNext);
	}
	return pHead;
}

void TestMerge()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(3);
	ListNode* pNode3 = CreateListNode(5);
	ListNode* pNode4 = CreateListNode(7);
	ListNode* pNode5 = CreateListNode(9);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	ListNode* pNode11 = CreateListNode(2);
	ListNode* pNode22 = CreateListNode(4);
	ListNode* pNode33 = CreateListNode(6);
	ListNode* pNode44 = CreateListNode(8);

	ConnectListNodes(pNode11, pNode22);
	ConnectListNodes(pNode22, pNode33);
	ConnectListNodes(pNode33, pNode44);

	PrintList(pNode1);
	PrintList(pNode11);
	ListNode* p=MergeList(pNode1,pNode11);
	PrintList(p);


	DestroyList(pNode1);
}