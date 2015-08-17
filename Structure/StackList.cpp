#include <iostream>

struct Stack
{
	int m_nData;
	Stack* m_pNext;
};

class MyStack
{
public:
	MyStack()
	{
		m_pStack=NULL;
	}
	MyStack(int value)
	{
		m_pStack->m_nData=value;
		m_pStack->m_pNext=NULL;
	}
	void Push(int data);
	void Pop();
	bool IsEmpty();
	int Top();
private:
	//链表表示，头结点表示栈顶;初始化为NULL
	Stack* m_pStack;
};

void MyStack::Push(int data)
{
	Stack* m_pTop=new Stack();
	m_pTop->m_nData=data;
	m_pTop->m_pNext=m_pStack;
	m_pStack=m_pTop;
}

void MyStack::Pop()
{
	//为空判断
	if (IsEmpty())
		return;
	Stack* temp=m_pStack;
	m_pStack=m_pStack->m_pNext;
	delete temp;
	temp=NULL;
}

bool MyStack::IsEmpty()
{
	return m_pStack==NULL;
}

int MyStack::Top()
{
	return m_pStack->m_nData;
}

void main()
{
	MyStack stack;
	stack.Push(1);
	stack.Push(4);
	stack.Push(7);
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Push(1);
	stack.Push(4);
	stack.Push(7);
}




