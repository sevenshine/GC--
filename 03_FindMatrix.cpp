#include<iostream>
using namespace std;

//rows:行 columns：列    int *matrix表示首元素
bool Find(int *matrix, int rows, int columns, int number)
{
	//1、用found来标识返回bool类型；
	bool found=false;
	//2、边界条件的判断，空指针和行列为正整数
	if(matrix!=NULL && rows>0 && columns>0)
	{
		int row=0;
		int column=columns-1;
		while(row<rows && column>=0)
		{
			//3、二维指针的表示方式；指针表示：*(p+1*4+2)   数组表示：*(*(a+1)+2) 
			if(*(matrix+row*columns+column)==number)
			{
				found=true;
				break;
			}
			else if(*(matrix+row*columns+column)>number)
				--column;
			else
				++row;
		}
	}
	return found;
}

// ====================测试代码====================

//通过Test编写统一的测试代码函数，在通过Test1，Test2传入要测试的数值
//测试数值：元素存在，不存在；最大值，最小值；比最大值大，比最小值小
void Test(char *name, int *matrix, int rows, int columns, int number)
{
	bool result=Find(matrix, rows, columns, number);
	if (result)
		cout<<name<<"  found"<<endl;
	else
		cout<<name<<"  not found"<<endl;
}

//元素存在
void Test1()
{
	int a[][4]={{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test1", a[0], 4, 4, 8);
}

//元素不存在
void Test2()
{
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test2", matrix[0], 4, 4, 5);
}

int main()
{
	Test1();
	Test2();
}