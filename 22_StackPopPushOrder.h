#pragma	once
#include <iostream>
#include <stack>
using namespace std;

//关键：栈结束判断，栈遍历结束退出、弹出序列遍历结束判断
//pNextPop-pPop<nLength
//stackData.top()!=*pNextPop
//stackData.empty() 
//pNextPop-pPop==nLength
//pNextPush-pPush==nLength

//1、形参指针的输入，整数序列的表示，int push[nLength]={1,2,3,4,5};
//2、用临时指针来遍历指针序列int* pNextPush=pPush;int* pNextPop=pPop;
//while (pNextPop-pPop<nLength)大小控制,遍历完弹出序列
bool IsPopOrder(int* pPush, int* pPop, int nLength)
{	
	bool result=false;

	if (pPush!=NULL && pPop!=NULL && nLength>0)
	{
		int* pNextPush=pPush;
		int* pNextPop=pPop;
		stack<int> stackData;

		while (pNextPop-pPop<nLength)
		{
			while (stackData.empty() || stackData.top()!=*pNextPop)
			{
				//输入栈全部压入
				if (pNextPush-pPush==nLength)
					break;
				stackData.push(*pNextPush);
				pNextPush++;
			}
			//栈元素和弹出序列对比，不相同则退出
			if (stackData.top()!=*pNextPop)
				break;

			stackData.pop();
			pNextPop++;
		}

		//正确条件判断：栈为空，弹出序列遍历到末尾
		if (stackData.empty() && pNextPop-pPop==nLength)
			result=true;
	}
	return result;
}

void Test()
{
	const int nLength=5;
	int push[nLength]={1,2,3,4,5};
	int pop[nLength]={4,5,3,2,1};
	bool test=IsPopOrder(push,pop,nLength);
}