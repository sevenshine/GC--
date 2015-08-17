#pragma	once
#include <iostream>
#include "BinaryTree.h"
using namespace std;

//注意出递归条件：if (pRoot->m_pLeft==NULL && pRoot->m_pRight==NULL)
//即找出递归条件，然后写递归程序；然后判断递归的条件if (pRoot->m_pLeft != NULL)
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
