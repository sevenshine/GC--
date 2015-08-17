#include<iostream>
using namespace std;
//双链表插入和删除结点
struct DoubleListNode
{
	int m_nData;
	DoubleListNode* m_pPrior;
	DoubleListNode* m_pNext;
};

//插入p后面的结点结点q,前后关系4种
void AddNode(DoubleListNode* p, DoubleListNode* q)
{
	q->m_pNext=p->m_pNext;
	p->m_pNext->m_pPrior=q;
	q->m_pPrior=p;
	p->m_pNext=q;
}

void DeleteNode(DoubleListNode* p, DoubleListNode* q)
{
	p->m_pNext=q->m_pNext;
	q->m_pPrior=p;
	delete q;
	q=NULL;
}


