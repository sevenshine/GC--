//char* str不能改变数值，故用数组；
//读取数组可用*，更改数组用数组直接传入
void ReplaceBlank(char str[], int length)
{
	//错误检测
	if(str==NULL && length<=0)
		return;

	//数组长度，特定元素读取
	//方案二：通过string[i]！='\0'来判断是否读到数组末尾
	int numberOfBlack=0;
	int originalLength=strlen(str);
	for(int i=0;i<originalLength;i++)
	{
		if(str[i]==' ')
			++numberOfBlack;			
	}

	//通过两个下标索引控制移动指针
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

// ====================测试代码====================
void Test(char *testName,char str[],int length)
{
	ReplaceBlank(str,length);
	//传入NULL时的特殊处理
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

