#include <iostream>
/*   ˳�������ʹ�С��ʵ��ջ��������   */
//ʵ��top(),push(),pop()��������
//ע��ṹ��ĳ�ʼ����stack.m_nSize=0;ջ���Ⱥ�����ĳ�ʼ��
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
	//m_nSize-1����ջ��
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
