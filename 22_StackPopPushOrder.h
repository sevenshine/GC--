#pragma	once
#include <iostream>
#include <stack>
using namespace std;

//�ؼ���ջ�����жϣ�ջ���������˳����������б��������ж�
//pNextPop-pPop<nLength
//stackData.top()!=*pNextPop
//stackData.empty() 
//pNextPop-pPop==nLength
//pNextPush-pPush==nLength

//1���β�ָ������룬�������еı�ʾ��int push[nLength]={1,2,3,4,5};
//2������ʱָ��������ָ������int* pNextPush=pPush;int* pNextPop=pPop;
//while (pNextPop-pPop<nLength)��С����,�����굯������
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
				//����ջȫ��ѹ��
				if (pNextPush-pPush==nLength)
					break;
				stackData.push(*pNextPush);
				pNextPush++;
			}
			//ջԪ�غ͵������жԱȣ�����ͬ���˳�
			if (stackData.top()!=*pNextPop)
				break;

			stackData.pop();
			pNextPop++;
		}

		//��ȷ�����жϣ�ջΪ�գ��������б�����ĩβ
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