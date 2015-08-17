#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
	void push(int x) {
		m_data.push(x);
		if (m_min.empty() || x<=m_min.top()){
			m_min.push(x);
		}
	}

	//为0判断，相同与否判断
	void pop() {
		if (m_data.empty()){
			return;
		}
		if (m_data.top()==m_min.top()){
			m_min.pop();
		}
		m_data.pop();
	}

	int top() {
		return m_data.top();
	}

	int getMin() {
		return m_min.top();
	}
private:
	stack<int> m_data;
	stack<int> m_min;
};


void main()
{
	cout << "--- expected output [0, 0, 0, 2]" << endl;
	MinStack ms;
	ms.push(2);
	ms.push(0);
	ms.push(3);
	ms.push(0);

	cout << ms.getMin() << endl;
	ms.pop();
	cout << ms.getMin() << endl;
	ms.pop();
	cout << ms.getMin() << endl;
	ms.pop();
	cout << ms.getMin() << endl;

}