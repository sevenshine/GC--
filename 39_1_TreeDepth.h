#pragma once
#include <iostream>

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

//���͵ݹ�����
int TreeDepth(BinaryTreeNode* pRoot)
{
	if (pRoot==NULL)
		return 0;

	int nLeft=TreeDepth(pRoot->m_pLeft);
	int nRight=TreeDepth(pRoot->m_pRight);

	return (nLeft>nRight)?(nLeft+1):(nRight+1);
}


//��TreeDepth�Ļ����Ͻ��еݹ飬������ظ��������
//ǰ�����
bool IsBalanceTree(BinaryTreeNode* pRoot)
{
	if (pRoot==NULL)
		return 0;

	int nLeft=TreeDepth(pRoot->m_pLeft);
	int nRight=TreeDepth(pRoot->m_pRight);

	int diff=nLeft-nRight;
	if (diff<-1 || diff>1)
		return false;

	bool t1=IsBalanceTree(pRoot->m_pLeft);
	bool t2=IsBalanceTree(pRoot->m_pRight);

	return  t1 && t2;
}


//---------------������-------------------
//1����������
//2����¼������������ȡ����������ؼ�

bool IsBalanced(BinaryTreeNode* pRoot, int &pDepth)
{
	if (pRoot==NULL)
	{
		pDepth=0;
		return true;
	}

	int left, right;
	bool t1=IsBalanced(pRoot->m_pLeft, left);
	bool t2=IsBalanced(pRoot->m_pRight, right);
	if (t1 && t2)
	{
		int diff=left-right;
		if (diff<-1 || diff>1)
		{
			pDepth=1+ (left>right ? left:right);
			return true;
		}
	}
	return false;
}

void IsBalanced(BinaryTreeNode* pRoot)
{
	int depth=0;
	IsBalanced(pRoot, depth);
}

