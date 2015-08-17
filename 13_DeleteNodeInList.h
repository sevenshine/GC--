#pragma once
#include <iostream>
using namespace std;


//检错判断：if(!pListHead || !pToBeDeleted)
//几种特殊状态的逻辑表示：是尾结点；不是尾结点，单结点，多结点
//将主体部分写在前面，一次return，而不是不停的if判断

//注意点：
//结点删除，内存释放后必须将指针置为NULL
//delete pToBeDeleted;pToBeDeleted = NULL;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	//非空判断
	if(!pListHead || !pToBeDeleted)
		return;

	// 要删除的结点不是尾结点
	if(pToBeDeleted->m_pNext != NULL)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = NULL;
	}
	// 单结点，删除头结点（也是尾结点）
	else if(*pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		//将两个相同的指针均置空
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	// 多结点
	else
	{
		ListNode* pNode = *pListHead;
		while(pNode->m_pNext != pToBeDeleted)
		{
			pNode = pNode->m_pNext;            
		}

		pNode->m_pNext = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}