#pragma	once
#include <iostream>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

//思路：两个指针p1,p2控制k-1的大小间隔
//注意点：控制鲁棒性
//1、链表空，k<1；返回值为NULL，而不是直接return
//2、链表长度不到k，通过if (p1->m_pNext!=NULL)来控制是否到达末尾
ListNode* FindKthToTail(ListNode* pListHead, int k)
{
	if (pListHead==NULL||k<1)
		return NULL;

	ListNode* p1=pListHead;
	while (k--)
	{
		if (p1->m_pNext!=NULL)
			p1=p1->m_pNext;
		else
			return NULL;
	}
	ListNode* p2=pListHead;
	while (p1->m_pNext!=NULL)
	{
		p1=p1->m_pNext;
		p2=p2->m_pNext;
	}
	return p2;
}
