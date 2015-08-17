#ifndef TEST_H_
#define TEST_H_

#include<iostream>
using namespace std;

struct ListNode
{
	int m_nData;
	ListNode* m_pNext;
};

//pNode�����ƽ�㣬pHead������ͷ���
//����һ��List���
ListNode* CreateListNode(int data)
{
	ListNode *pNode=new ListNode();
	pNode->m_nData=data;
	pNode->m_pNext=NULL;
	return pNode;
}

//����������
void ConnectListNodes(ListNode* pCurrent,ListNode* pNext)
{
	//��ǰ���Ϊ��ʱ�Ĵ�����
	if (pCurrent==NULL)
	{
		cout<<"Error to connect two nodes."<<endl;
		exit(1);
	}
	pCurrent->m_pNext=pNext;
}

//����List��ͨ�������½��pNode������List
void PrintList(ListNode* pHead)
{
	//������ӡʱ�����޸�ͷ���ָ�룬����Ҫ�м�������ӡ���
	/*while(pHead!=NULL)
	{
	cout<<pHead->m_nData<<endl;
	pHead=pHead->m_pNext;
	}*/

	ListNode* pNode=pHead;
	while (pNode!=NULL)
	{
		cout<<pNode->m_nData<<"\t";
		pNode = pNode->m_pNext;
	}
	cout<<endl;
}

//ͨ��pNode������Ҫɾ�����Ǹ����
void DestroyList(ListNode* pHead)
{
	ListNode* pNode=pHead;
	while (pNode!=NULL)
	{
		pHead=pHead->m_pNext;
		delete pNode;
		pNode=pHead;
	}
}

//�ս��Ŀ��ǣ�����˫ָ��
void AddToTail(ListNode** pHead, int data)
{
	ListNode* pNode=*pHead;
	ListNode* pNew=new ListNode();
	pNew->m_nData=data;
	pNew->m_pNext=NULL;

	if (*pHead==NULL)
	{
		//pHead->m_pNext=pNew;   ��NULL��㸳ֵ�ᷢ�����ʳ�ͻ
		*pHead=pNew;
	}
	else
	{
		//pNode!=NULL,pNode�������һ�����ʱ�˳���������pNode=NULLʱ�˳�
		while (pNode->m_pNext!=NULL)
		{
			pNode=pNode->m_pNext;
		}
		pNode->m_pNext=pNew;
	}
}

//����pToBeDeleted���������ˣ���������ͷ�
//ͷ���pHead���������pNode->next�ֿ�����
//���ǿ�����������Ҫ�����άָ�룬ListNode **pHead��ʹ��ʱֻҪ��*pHead��ʹ��ͷ��㣬�������ͬ
void RemoveNode(ListNode **pHead,int value)
{
	if(pHead==NULL||*pHead==NULL)
		return;

	ListNode* pToBeDeleted=NULL;
	if ((*pHead)->m_nData==value)
	{
		pToBeDeleted=*pHead;
		*pHead=(*pHead)->m_pNext;
	}
	else
	{
		ListNode *pNode=*pHead;
		while (pNode->m_pNext!=NULL)
		{
			if(pNode->m_pNext->m_nData==value)
			{
				pToBeDeleted=pNode->m_pNext;
				pNode->m_pNext=pNode->m_pNext->m_pNext;
				break;
			}
			pNode=pNode->m_pNext;
		}
	}

	//ע��㣺ɾ������ͷ�
	if (pToBeDeleted!=NULL)
	{
		delete pToBeDeleted;
		pToBeDeleted=NULL;
	}
}

void Test()
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
	AddToTail(&pNode1,6);
	PrintList(pNode1);
	RemoveNode(&pNode1,3);
	RemoveNode(&pNode1,6);
	RemoveNode(&pNode1,1);
	PrintList(pNode1);

	ListNode* pNode=NULL;
	AddToTail(&pNode,1);
	PrintList(pNode);

	DestroyList(pNode1);
}

#endif