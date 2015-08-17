#pragma	once
#include <iostream>
using namespace std;

//����ֽ⣺��ѭ����ӡ����PrintMatrix()��ÿ�δ�ӡһȦPrintMatrixInCircle()

//ע��㣺����ı�ʾ
//�ؼ��㣺PrintMatrix()�������ҳ�ѭ�����ж�����
//PrintMatrixInCircle()�����ж�λȦ����ʼ���A(start,start),�Խǽ������B(endX,endY)
//����A(start,start)��B(endX,endY)�����ӡ���ж���������ͼȷ�ϱ߽�ͼ
void PrintMatrix(int** numbers, int columns, int rows)
{
	if (numbers==NULL || columns<=0 || rows<=0)
		return;

	int start=0;
	while (columns>start*2 && rows>start*2)
	{
		PrintMatrixInCircle(numbers, columns, rows, start);
		start++;
	}
}

//��ӡһȦ��������һȦ
void PrintMatrixInCircle(int** numbers, int columns, int rows, int start)
{
	int endX=columns-1-start;
	int endY=rows-1-start;

	for (int i=start; i<endX; ++i)
	{
		int data=numbers[start][i];
		cout<<data<<" ";
	}

	//���ϵ��´�ӡһ�У���Ҫ�ж�����start<endY
	if (start<endY)
	{
		for (int i=start+1; i<=endY; ++i)
		{
			int data=numbers[i][endX];
			cout<<data<<" ";
		}
	}

	//���ҵ����ж�����
	//���µ��ϣ��ж�����

}
