#pragma	once
#include <iostream>
#include "List.h"
using namespace std;

/* 链表反转，本实例，循环代码比递归代码简洁 */
//递归实现，注意递归实现的返回，通过测试来判断递归的正确性：eg：list为1,2输入
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

//1、用pReverseHead来表示新链表
//2、循环结束判断，pNode!=NULL，或者pNext==NULL
//3、用图来分析循环过程，先写出关键代码
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