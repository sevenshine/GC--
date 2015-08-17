#pragma once

#include <iostream>
#include <stack>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode *pNode=new BinaryTreeNode();
	pNode->m_nValue=value;
	pNode->m_pLeft=NULL;
	pNode->m_pRight=NULL;
	return pNode;
}

//错误判断	pParent!=NULL
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent!=NULL)
	{
		pParent->m_pLeft=pLeft;
		pParent->m_pRight=pRight;
	}
}

void PrintTreeNode(BinaryTreeNode* pNode)
{
}

void PrintTree(BinaryTreeNode* pRoot)
{
}

void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot!=NULL)
	{
		BinaryTreeNode* pLeft=pRoot->m_pLeft;
		BinaryTreeNode* pRight=pRoot->m_pRight;

		delete pRoot;
		pRoot=NULL;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}

//6中方法遍历二叉树
void PreOrder(BinaryTreeNode* pNode)
{
	if (pNode!=NULL)
	{
		cout<<pNode->m_nValue<<"\t";
		PreOrder(pNode->m_pLeft);
		PreOrder(pNode->m_pRight);
	}
}

//循环前序遍历，将需要保存右子树的结点用栈保存，左右节点遍历后该根结点pop出栈
//http://blog.csdn.net/fansongy/article/details/6798278
void PreOrder2(BinaryTreeNode* pRoot)
{
	BinaryTreeNode* pNode=pRoot;
	stack<BinaryTreeNode*> nodes;
	while (pNode||!nodes.empty())
	{
		//while遍历到左子树叶子结点，然后通过pNode=nodes.top()返回叶子结点，nodes.pop()返回根结点
		while (pNode!=NULL)
		{
			cout<<pNode->m_nValue<<"\t";
			nodes.push(pNode);
			pNode=pNode->m_pLeft;
		}
		pNode=nodes.top();
		nodes.pop();
		pNode=pNode->m_pRight;
	}	
}

void InOrder(BinaryTreeNode* pNode)
{
	if (pNode!=NULL)
	{
		PreOrder(pNode->m_pLeft);
		cout<<pNode->m_nValue<<"\t";
		PreOrder(pNode->m_pRight);
	}
}

//相对于前序循环，只是打印顺序放在了不同位置，中序遍历是将栈pop()出来的节点给依次打印出来
void InOrder2(BinaryTreeNode* pRoot)
{
	BinaryTreeNode* pNode=pRoot;
	stack<BinaryTreeNode*> nodes;
	while (pNode||!nodes.empty())
	{
		while (pNode!=NULL)
		{
			nodes.push(pNode);
			pNode=pNode->m_pLeft;
		}
		pNode=nodes.top();
		cout<<pNode->m_nValue<<"\t";
		nodes.pop();
		pNode=pNode->m_pRight;
	}
}

void PostOrder(BinaryTreeNode* pNode)
{
	if (pNode!=NULL)
	{
		PreOrder(pNode->m_pLeft);
		PreOrder(pNode->m_pRight);
		cout<<pNode->m_nValue<<"\t";
	}
}


//创建二叉树，先创建二叉树结点，然后再将结点和左右结点相连
//建好二叉树后就可以进行各种方式的遍历了
void Test()
{
	//new 在堆上新建新结点
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

	PreOrder2(pNode1);
	cout<<endl;
	InOrder2(pNode1);
	cout<<endl;
	PostOrder(pNode1);
	cout<<endl;
}