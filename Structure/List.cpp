#include<iostream>
using namespace std;
//˫��������ɾ�����
struct DoubleListNode
{
	int m_nData;
	DoubleListNode* m_pPrior;
	DoubleListNode* m_pNext;
};

//����p����Ľ����q,ǰ���ϵ4��
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


