#pragma	once
#include <iostream>
using namespace std;

//��1���ֳ�����������ֽ⣩���ַ���huo����ģ���������ӣ��ַ�����ʼ��0����ӡʡ��0���ַ���
//��2��ȫ����ѭ��ʵ�֣��������ַ������������

// ====================����һ====================
//demo:���ַ����ĳ�ʼ��Ϊ0��
//�ַ���������Ҫ�ı��ö�̬�ڴ棻����Ҳ���Ըı�����

void Print1ToMaxOfNDigits_1(int n)
{
	if (n<0)
		return ;
	
	//���ַ���number��ӡ�����ַ����ĳ�ʼ��Ϊ0��
	//�������붯̬�ڴ�n+1����delete[] number�ͷ�
	//memset��numberָ���ǰn�ֽ�ְλ'0',��n+1��Ϊ'\0'
	char *number=new char[n+1];
	memset(number,'0',n);
	number[n]='\0';

	while(!Increase(number))
	{
		PrintNumber(number);
	}
	delete[] number;
}

//���ַ���ģ������+1����Ҫ������ĩλ+1����10���λ����λʱ��������ж�
//����ʵ�֣���number������+1���޸��ַ���number
//�����־λ��bool�����ж��Ƿ���� && ��λ��־λ��nSum>=10�ж��Ƿ��λ
bool Increase(char* number)
{
	bool isOverFlow=false;	//�����־
	int nCarry=0;			//��λ��־
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

//��ȥ0��ӡ�ַ�����
//forѭ�������ַ�����ͨ����־λisBeginning0���ж��Ƿ���Ҫ��ӡ
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


// ====================������====================
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

