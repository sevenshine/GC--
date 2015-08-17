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

//注：函数理清过程和基本程序代码，未测试
//通过两组序列定位出结点pRoot和左右子树，再依次构建左子树和右子树递归实现
//1、确定root结点
//2、在中序结点中找到root结点的值*p，通过指针确定左右子树的范围
//3、递归返回
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
