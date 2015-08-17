#pragma once
#include <iostream>
#include <exception>
using namespace std;

//���鴫�룬(int* numbers, int length),���ı��������ݣ��±�ֱ�Ӷ�ȡ��
//(int numbers[], int length)�ɸı���������
//������ö��ַ���ѭ��ʵ��,���⼴Ϊ���ַ���Ӧ�ã�����ֱ�Ӹ���Ӧ�ö��ַ����ң�ͬʱ���Ƕ���߽�
//��������������ת��ֱ�ӷ���
int Min(int* numbers, int length)
{
	if (numbers==NULL||length<=0)
		throw new exception("invalid patameters");

	int index1=0;
	int index2=length-1;
	int indexMid=index1;//����ֱ�ӷ��أ����Գ�ʼ��Ϊindex1
	// ���index1��index2ָ�����ڵ���������
	// ��index1ָ���һ����������������һ�����֣�
	// index2ָ��ڶ���������ĵ�һ�����֣�Ҳ���������е���С����
	while (numbers[index1]>=numbers[index2])
	{
		if (index2-index1==1)
		{
			indexMid=index2;
			break;
		}
		indexMid=(index1+index2)/2;

		// ����±�Ϊindex1��index2��indexMidָ�������������ȣ�
		// ��ֻ��˳����ң�����
		if (numbers[index1] == numbers[index2]&&numbers[indexMid] == numbers[index1])
		{
			return MinInOrder(numbers, index1, index2);
		}

		// ��С���ҷ�Χ

		if (numbers[indexMid]>=numbers[index1])
		{
			index1=indexMid;
		}
		else if (numbers[indexMid]<=numbers[index2])
		{
			index2=indexMid;
		}
	}
	return numbers[indexMid];
}

int MinInOrder(int* numbers, int index1, int index2)
{
	int result = numbers[index1];
	for(int i = index1 + 1; i <= index2; ++i)
	{
		if(result > numbers[i])
			result = numbers[i];
	}

	return result;
}