#pragma once
#include <iostream>
using namespace std;


//����жϣ�if(!pListHead || !pToBeDeleted)
//��������״̬���߼���ʾ����β��㣻����β��㣬����㣬����
//�����岿��д��ǰ�棬һ��return�������ǲ�ͣ��if�ж�

//ע��㣺
//���ɾ�����ڴ��ͷź���뽫ָ����ΪNULL
//delete pToBeDeleted;pToBeDeleted = NULL;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	//�ǿ��ж�
	if(!pListHead || !pToBeDeleted)
		return;

	// Ҫɾ���Ľ�㲻��β���
	if(pToBeDeleted->m_pNext != NULL)
	{
		ListNode* pNext = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = pNext->m_nValue;
		pToBeDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext = NULL;
	}
	// ����㣬ɾ��ͷ��㣨Ҳ��β��㣩
	else if(*pListHead == pToBeDeleted)
	{
		delete pToBeDeleted;
		//��������ͬ��ָ����ÿ�
		pToBeDeleted = NULL;
		*pListHead = NULL;
	}
	// ����
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