//char* str���ܸı���ֵ���������飻
//��ȡ�������*����������������ֱ�Ӵ���
void ReplaceBlank(char str[], int length)
{
	//������
	if(str==NULL && length<=0)
		return;

	//���鳤�ȣ��ض�Ԫ�ض�ȡ
	//��������ͨ��string[i]��='\0'���ж��Ƿ��������ĩβ
	int numberOfBlack=0;
	int originalLength=strlen(str);
	for(int i=0;i<originalLength;i++)
	{
		if(str[i]==' ')
			++numberOfBlack;			
	}

	//ͨ�������±����������ƶ�ָ��
	int indexA=originalLength;
	int indexB=originalLength+numberOfBlack*2;
	while(indexA>=0)
	{
		if(str[indexA]!=' ')
			str[indexB]=str[indexA];
		else
		{
			--numberOfBlack;
			indexB-=2;
			str[indexB]='%';
			str[indexB+1]='2';
			str[indexB+2]='0';
		}
		--indexA;
		--indexB;
	}
}

// ====================���Դ���====================
void Test(char *testName,char str[],int length)
{
	ReplaceBlank(str,length);
	//����NULLʱ�����⴦��
	if(str == NULL)
		cout<<"NULL"<<endl;
	else
		cout<<str<<endl;
}

void Test1()
{
	char str[50]="hello world";
	Test("Test1",str,50);
}
void Test2()
{
	Test("Test2",NULL,0);
}
void Test3()
{
	char str[50]=" ";
	ReplaceBlank(str,50);
	cout<<str<<endl;
}
int main()
{
	Test1();
	Test2();
	Test3();
}

