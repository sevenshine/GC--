#pragma	once
#include <iostream>
#include "BinaryTree.h"
using namespace std;

//��������ֽ��������ݹ�˼�룬ʹ�����εݹ�
//������1���ݹ�����ҳ��������ͬ������2���ж��������Ƿ���ͬ

//ͨ��result�����Ʒ��صĽ�����л���û��
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

//���жϸ������ͬ�����Ƿ������
//�ж����ݣ�pRoot2 == NULL��pRoot1 ==NULL�����ֵ�Ƿ���ͬ���������ж�
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