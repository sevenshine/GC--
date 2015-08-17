#pragma	once
#include <iostream>
using namespace std;

//法1：分成两步（问题分解）：字符串huo数组模拟数字增加；字符串初始化0，打印省略0的字符串
//法2：全排列循环实现，两步：字符串逐个遍历；

// ====================方法一====================
//demo:【字符串的初始化为0】
//字符串内容需要改变用动态内存；数组也可以改变内容

void Print1ToMaxOfNDigits_1(int n)
{
	if (n<0)
		return ;
	
	//用字符串number打印，【字符串的初始化为0】
	//堆上申请动态内存n+1，用delete[] number释放
	//memset将number指向的前n字节职位'0',第n+1置为'\0'
	char *number=new char[n+1];
	memset(number,'0',n);
	number[n]='\0';

	while(!Increase(number))
	{
		PrintNumber(number);
	}
	delete[] number;
}

//【字符串模拟数字+1】需要操作：末位+1，到10则进位；进位时进行溢出判断
//函数实现：在number基础上+1，修改字符串number
//溢出标志位，bool返回判断是否溢出 && 进位标志位，nSum>=10判断是否进位
bool Increase(char* number)
{
	bool isOverFlow=false;	//溢出标志
	int nCarry=0;			//进位标志
	int nLength=strlen(number);
	for (int i=nLength-1;i>=0;i--)
	{
		int nSum=number[i]-'0'+nCarry;
		if (i==nLength-1)
			nSum++;

		if (nSum>=10)
		{
			if (i==0)
				isOverFlow=true;
			else
			{
				nSum-=10;
				nCarry=1;
				number[i]='0'+nSum;
			}
		}
		else
		{
			number[i]+=nSum+'0';
			break;
		}
	}
	return isOverFlow;
}

//【去0打印字符串】
//for循环遍历字符串，通过标志位isBeginning0来判断是否需要打印
void PrintNumber(char* number)
{
	bool isBeginning0=true;
	int nLength=strlen(number);

	for (int i=0;i<nLength;i++)
	{
		if (isBeginning0 && number[i]!='0')
		{
			isBeginning0=false;
		}
		if (!isBeginning0)
		{
			cout<<number[i];
		}
	}
}


// ====================方法二====================
void Print1ToMaxOfNDigits_2(int n)
{
	if (n<=0)
		return ;

	char* number=new char[n+1];
	number[n]='\0';

	for (int i=0;i<10;i++)
	{
		number[0]=i+'0';
		Print1ToMaxOfNDigitsRecursively(number,n,0);
	}
	delete[] number;
}

void Print1ToMaxOfNDigitsRecursively(char* number,int length,int index)
{
	if (index==length-1)
	{
		PrintNumber(number);
		return;
	}

	for (int i=0;i<10;i++)
	{
		number[index+1]=i+'0';
		Print1ToMaxOfNDigitsRecursively(number,length,index+1);
	}
}

