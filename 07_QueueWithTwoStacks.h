#pragma once

#include <iostream>
#include <stack>

using namespace std;

//考察栈和队列的理解
//template相关代码的书写
template <typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	// 在队列末尾添加一个结点
	void appendTail(const T& node);

	// 删除队列的头结点
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

//构造函数和析构函数在声明后需要在后面实现，否则会出现错误
template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}

template<typename T> void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template<typename T> T CQueue<T>::deleteHead()
{
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			//??
			T& data=stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if (stack2.empty())
	{
		cout<<"no data"<<endl;
	}

	T head=stack2.top();
	stack2.pop();

	return head;
}

void Test()
{
	CQueue<char> queue;
	queue.appendTail('a');
	queue.appendTail('b');
	queue.appendTail('c');

	char head=queue.deleteHead();
	cout<<head<<endl;

	head=queue.deleteHead();
	cout<<head<<endl;

	queue.appendTail('d');
	head=queue.deleteHead();
	cout<<head<<endl;

	queue.appendTail('e');
	head=queue.deleteHead();
	cout<<head<<endl;

	head=queue.deleteHead();
	cout<<head<<endl;
}


