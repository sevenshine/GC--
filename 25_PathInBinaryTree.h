#pragma 
#include <iostream>
#include <stack>
#include "BinaryTree.h"
using namespace std;

void PathInTree(BinaryTreeNode* pRoot, int expectedSum)
{
	stack<BinaryTreeNode*> nodes;
	nodes.push(pRoot);
	while (nodes.size())
	{
		while (pRoot->m_pLeft!=NULL)
		{
			nodes.push(pRoot->m_pLeft);
		}
		nodes.pop();
		if (pRoot->m_pRight!=NULL)
		{
			nodes.push(pRoot->m_pRight);
		}
	}
}