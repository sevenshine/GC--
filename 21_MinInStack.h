#pragma	once
#include <iostream>
#include <stack>
using namespace std;

//关键：辅助栈的使用(存放最小元素)
//const T&注意const引用；template书写格式
//类引用MinStack<int> stack；直接用<int>来确定<T>的值
template <typename T> class MinStack {
public:
	MinStack() {}
	virtual ~MinStack() {}

	void push(const T& x);

	//为0判断，相同与否判断
	void pop();
	
	const T& top() const;
	
	const T& getMin() const;
	
private:
	stack<int> m_data;
	stack<int> m_min;
};

template <typename T> void MinStack<T>::push(const T& x) 
{
	m_data.push(x);
	if (m_min.empty() || x<=m_min.top())
		m_min.push(x);
	else
		m_min.push(m_min.top());
}

//为0判断，相同与否判断
template <typename T> void MinStack<T>::pop() 
{
	if (m_data.empty())
	{
		return;
	}
	if (m_data.top()==m_min.top())
	{
		m_min.pop();
	}
	m_data.pop();
}

template <typename T> T& MinStack<T>::top() const
{
	return m_data.top();
}

template <typename T> T& MinStack<T>::getMin() const
{
	return m_min.top();
}

void Test()
{
	MinStack<int> stack;
	stack.push(2);
	stack.push(0);
	stack.push(3);
	stack.push(0);

	cout << stack.getMin() << endl;
	stack.pop();
	cout << stack.getMin() << endl;
	stack.pop();
	cout << stack.getMin() << endl;
	stack.pop();
	cout << stack.getMin() << endl;
}


