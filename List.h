#ifndef TEST_H_
#define TEST_H_

#include<iostream>
using namespace std;

struct ListNode
{
	int m_nData;
	ListNode* m_pNext;
};

//pNode来控制结点，pHead来控制头结点
//创建一个List结点
ListNode* CreateListNode(int data)
{
	ListNode *pNode=new ListNode();
	pNode->m_nData=data;
	pNode->m_pNext=NULL;
	return pNode;
}

//两结点的连接
void ConnectListNodes(ListNode* pCurrent,ListNode* pNext)
{
	//当前结点为空时的错误处理
	if (pCurrent==NULL)
	{
		cout<<"Error to connect two nodes."<<endl;
		exit(1);
	}
	pCurrent->m_pNext=pNext;
}

//遍历List，通过创建新结点pNode来遍历List
void PrintList(ListNode* pHead)
{
	//函数打印时不能修改头结点指针，故需要中间结点来打印输出
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

//通过pNode来控制要删除的那个结点
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

//空结点的考虑，？？双指针
void AddToTail(ListNode** pHead, int data)
{
	ListNode* pNode=*pHead;
	ListNode* pNew=new ListNode();
	pNew->m_nData=data;
	pNew->m_pNext=NULL;

	if (*pHead==NULL)
	{
		//pHead->m_pNext=pNew;   给NULL结点赋值会发生访问冲突
		*pHead=pNew;
	}
	else
	{
		//pNode!=NULL,pNode到达最后一个结点时退出，而不是pNode=NULL时退出
		while (pNode->m_pNext!=NULL)
		{
			pNode=pNode->m_pNext;
		}
		pNode->m_pNext=pNew;
	}
}

//申明pToBeDeleted，清晰明了，用来最后释放
//头结点pHead和其他结点pNode->next分开考虑
//考虑空链表，导致需要传入二维指针，ListNode **pHead，使用时只要用*pHead来使用头结点，其余均相同
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

	//注意点：删除结点释放
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