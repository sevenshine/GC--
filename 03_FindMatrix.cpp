#include<iostream>
using namespace std;

//rows:�� columns����    int *matrix��ʾ��Ԫ��
bool Find(int *matrix, int rows, int columns, int number)
{
	//1����found����ʶ����bool���ͣ�
	bool found=false;
	//2���߽��������жϣ���ָ�������Ϊ������
	if(matrix!=NULL && rows>0 && columns>0)
	{
		int row=0;
		int column=columns-1;
		while(row<rows && column>=0)
		{
			//3����άָ��ı�ʾ��ʽ��ָ���ʾ��*(p+1*4+2)   �����ʾ��*(*(a+1)+2) 
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

// ====================���Դ���====================

//ͨ��Test��дͳһ�Ĳ��Դ��뺯������ͨ��Test1��Test2����Ҫ���Ե���ֵ
//������ֵ��Ԫ�ش��ڣ������ڣ����ֵ����Сֵ�������ֵ�󣬱���СֵС
void Test(char *name, int *matrix, int rows, int columns, int number)
{
	bool result=Find(matrix, rows, columns, number);
	if (result)
		cout<<name<<"  found"<<endl;
	else
		cout<<name<<"  not found"<<endl;
}

//Ԫ�ش���
void Test1()
{
	int a[][4]={{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Test("Test1", a[0], 4, 4, 8);
}

//Ԫ�ز�����
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