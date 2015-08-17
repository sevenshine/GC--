#pragma	once
#include <iostream>
#include "BinaryTree.h"
using namespace std;

//考察问题分解能力，递归思想，使用两次递归
//两步：1、递归遍历找出根结点相同的树；2、判断两棵树是否相同

//通过result来控制返回的结果，有还是没有
bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool result=false;
	if (pRoot1!=NULL)
	{
		if(pRoot1->m_nValue == pRoot2->m_nValue)
			result = DoesTree1HaveTree2(pRoot1,pRoot2);
		if(!result)
			result = HasSubTree(pRoot1->m_pLeft,pRoot2);
		if(!result)
			result = HasSubTree(pRoot1->m_pRight,pRoot2);
	}
	return result;
}

//【判断根结点相同的树是否包含】
//判断依据：pRoot2 == NULL；pRoot1 ==NULL；结点值是否相同。共三处判断
bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot2 == NULL)
		return true;

	if (pRoot1 ==NULL)
		return false;

	if (pRoot1->m_nValue != pRoot2->m_nValue)
		return false;
	
	return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}