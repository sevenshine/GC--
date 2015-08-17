#pragma	once
#include <iostream>
using namespace std;

//问题分解：用循环打印矩阵PrintMatrix()，每次打印一圈PrintMatrixInCircle()

//注意点：矩阵的表示
//关键点：PrintMatrix()函数中找出循环的判断条件
//PrintMatrixInCircle()函数中定位圈的起始结点A(start,start),对角结点坐标B(endX,endY)
//根据A(start,start)和B(endX,endY)计算打印的判断条件，画图确认边界图
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

//打印一圈，即遍历一圈
void PrintMatrixInCircle(int** numbers, int columns, int rows, int start)
{
	int endX=columns-1-start;
	int endY=rows-1-start;

	for (int i=start; i<endX; ++i)
	{
		int data=numbers[start][i];
		cout<<data<<" ";
	}

	//从上倒下打印一列，需要判断条件start<endY
	if (start<endY)
	{
		for (int i=start+1; i<=endY; ++i)
		{
			int data=numbers[i][endX];
			cout<<data<<" ";
		}
	}

	//从右到左，判断条件
	//从下到上，判断条件

}
