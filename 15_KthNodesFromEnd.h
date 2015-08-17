#pragma	once
#include <iostream>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

//˼·������ָ��p1,p2����k-1�Ĵ�С���
//ע��㣺����³����
//1������գ�k<1������ֵΪNULL��������ֱ��return
//2�������Ȳ���k��ͨ��if (p1->m_pNext!=NULL)�������Ƿ񵽴�ĩβ
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
