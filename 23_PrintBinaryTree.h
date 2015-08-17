#pragma 
#include <iostream>
#include <queue>
#include "BinaryTree.h"
using namespace std;


//【二叉树层次遍历】vector来表示队列
void PrintBinaryTree(BinaryTreeNode* root)
{
	if (root=NULL)
		return;
	vector<BinaryTreeNode*> vec;

	vec.push_back(root);
	//cur表示每层开始，last表示末尾结点
	int cur=0;
	int last=1;
	while (cur<vec.size())
	{
		last=vec.size();
		while (cur<last)
		{
			cout<<vec[cur]->m_nValue<<" ";
			if (vec[cur]->m_pLeft)
				vec.push_back(vec[cur]->m_pLeft);
			if (vec[cur]->m_pRight)
				vec.push_back(vec[cur]->m_pRight);
			cur++;
		}
		cout<<endl;		//每层隔行打印
	}
}

void PrintBinaryTree(BinaryTreeNode* pRoot)
{
	if (pRoot==NULL)
		return;

	queue<BinaryTreeNode*> nodes;
	nodes.push(pRoot);
	while (nodes.size())
	{
		BinaryTreeNode* pNode=nodes.front();
		cout<<pNode->m_nValue<<"\t";
		nodes.pop();
		if (pNode->m_pLeft!=NULL)
			nodes.push(pNode->m_pLeft);
		if (pNode->m_pRight!=NULL)
			nodes.push(pNode->m_pRight);
	}
}

void Test23()
{
	BinaryTreeNode* pNode1=new BinaryTreeNode();
	BinaryTreeNode* pNode2=new BinaryTreeNode();
	BinaryTreeNode* pNode3=new BinaryTreeNode();
	BinaryTreeNode* pNode4=new BinaryTreeNode();
	BinaryTreeNode* pNode5=new BinaryTreeNode();
	BinaryTreeNode* pNode6=new BinaryTreeNode();
	BinaryTreeNode* pNode7=new BinaryTreeNode();

	pNode1=CreateBinaryTreeNode(10);
	pNode2=CreateBinaryTreeNode(6);
	pNode3=CreateBinaryTreeNode(4);
	pNode4=CreateBinaryTreeNode(8);
	pNode5=CreateBinaryTreeNode(14);
	pNode6=CreateBinaryTreeNode(12);
	pNode7=CreateBinaryTreeNode(16);

	ConnectTreeNodes(pNode1,pNode2,pNode5);
	ConnectTreeNodes(pNode2,pNode3,pNode4);
	ConnectTreeNodes(pNode5,pNode6,pNode7);

	PrintBinaryTree(pNode1);
}

