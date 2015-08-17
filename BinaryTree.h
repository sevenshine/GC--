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

//�����ж�	pParent!=NULL
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

//6�з�������������
void PreOrder(BinaryTreeNode* pNode)
{
	if (pNode!=NULL)
	{
		cout<<pNode->m_nValue<<"\t";
		PreOrder(pNode->m_pLeft);
		PreOrder(pNode->m_pRight);
	}
}

//ѭ��ǰ�����������Ҫ�����������Ľ����ջ���棬���ҽڵ������ø����pop��ջ
//http://blog.csdn.net/fansongy/article/details/6798278
void PreOrder2(BinaryTreeNode* pRoot)
{
	BinaryTreeNode* pNode=pRoot;
	stack<BinaryTreeNode*> nodes;
	while (pNode||!nodes.empty())
	{
		//while������������Ҷ�ӽ�㣬Ȼ��ͨ��pNode=nodes.top()����Ҷ�ӽ�㣬nodes.pop()���ظ����
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

//�����ǰ��ѭ����ֻ�Ǵ�ӡ˳������˲�ͬλ�ã���������ǽ�ջpop()�����Ľڵ�����δ�ӡ����
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


//�������������ȴ�����������㣬Ȼ���ٽ��������ҽ������
//���ö�������Ϳ��Խ��и��ַ�ʽ�ı�����
void Test()
{
	//new �ڶ����½��½��
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