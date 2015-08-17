#pragma once
#include <iostream>
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder==NULL || inorder==NULL || length<=0)
		return NULL;
	return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}

//ע������������̺ͻ���������룬δ����
//ͨ���������ж�λ�����pRoot�����������������ι������������������ݹ�ʵ��
//1��ȷ��root���
//2�������������ҵ�root����ֵ*p��ͨ��ָ��ȷ�����������ķ�Χ
//3���ݹ鷵��
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, 
	int* startInorder, int* endInorder)
{
	int rootValue=startPreorder[0];
	BinaryTreeNode* pRoot=new BinaryTreeNode();
	pRoot->m_nValue=rootValue;
	pRoot->m_pLeft=pRoot->m_pRight=NULL;

	int* p=startInorder;
	while (p!=startInorder)
	{
		if (*p==rootValue)
		{
			break;
		}
		p++;
	}

	int leftLength=p-startInorder;
	if (leftLength>0)
	{
		pRoot->m_pLeft=ConstructCore(startPreorder+1,startPreorder+leftLength,
			startInorder,startInorder+leftLength-1);
	}

	if (leftLength<endPreorder-startPreorder)
	{
		pRoot->m_pRight=ConstructCore(startPreorder+leftLength+1,endPreorder,
			startInorder+leftLength+1,endInorder);
	}
	return pRoot;
}
