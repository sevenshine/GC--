#pragma	once
#include <iostream>
#include <stack>
using namespace std;

//�ؼ�������ջ��ʹ��(�����СԪ��)
//const T&ע��const���ã�template��д��ʽ
//������MinStack<int> stack��ֱ����<int>��ȷ��<T>��ֵ
template <typename T> class MinStack {
public:
	MinStack() {}
	virtual ~MinStack() {}

	void push(const T& x);

	//Ϊ0�жϣ���ͬ����ж�
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

//Ϊ0�жϣ���ͬ����ж�
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


