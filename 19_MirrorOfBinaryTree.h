#pragma	once
#include <iostream>
#include "BinaryTree.h"
using namespace std;

//ע����ݹ�������if (pRoot->m_pLeft==NULL && pRoot->m_pRight==NULL)
//���ҳ��ݹ�������Ȼ��д�ݹ����Ȼ���жϵݹ������if (pRoot->m_pLeft != NULL)
void MirrorRecursively(BinaryTreeNode* pRoot)
{
	if (pRoot!=NULL)
		return;
	if (pRoot->m_pLeft==NULL && pRoot->m_pRight==NULL)
		return;

	BinaryTreeNode* pNode=pRoot->m_pLeft;
	pRoot->m_pLeft=pRoot->m_pRight;
	pRoot->m_pRight=pNode;

	if (pRoot->m_pLeft != NULL)
		MirrorRecursively(pRoot->m_pLeft);
	if (pRoot->m_pRight != NULL)
		MirrorRecursively(pRoot->m_pRight);
}

void MirrorRecurrence(BinaryTreeNode* pRoot)
{

}
