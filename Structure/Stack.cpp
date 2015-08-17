#include <iostream>
/*   顺序表（数组和大小）实现栈操作函数   */
//实现top(),push(),pop()三个功能
//注意结构体的初始化，stack.m_nSize=0;栈长度和数组的初始化
#define Maxm_nSize 50
struct STACK 
{
	int m_nData[Maxm_nSize];
	int m_nSize;
};

bool IsEmpty(STACK &stack)
{
	if (stack.m_nSize==0)
		return true;
	else
		return false;
}

bool Pop(STACK &stack)
{
	if (stack.m_nSize>0)
	{
		stack.m_nData[stack.m_nSize--]='\0';
		return true;
	}
	else
		return true;
}

bool Push(STACK &stack, int m_nData)
{
	if (stack.m_nSize<Maxm_nSize)
	{
		stack.m_nData[stack.m_nSize++]=m_nData;
		stack.m_nData[stack.m_nSize]='\0';
		return true;
	}
	else
		return false;
}

int Top(STACK &stack)
{
	//m_nSize-1返回栈顶
	return stack.m_nData[stack.m_nSize-1];
}

void main()
{
	STACK stack;
	stack.m_nSize=0;
	Push(stack, 1);
	Push(stack, 10);
	Push(stack, 6);
	Push(stack, 4);
	Push(stack, 7);
	int top=Top(stack);
	Pop(stack);
	Pop(stack);
	Pop(stack);
	Pop(stack);
}
