#pragma once

#include <iostream>
#include <stack>

using namespace std;

//����ջ�Ͷ��е����
//template��ش������д
template <typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	// �ڶ���ĩβ���һ�����
	void appendTail(const T& node);

	// ɾ�����е�ͷ���
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

//���캯����������������������Ҫ�ں���ʵ�֣��������ִ���
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


