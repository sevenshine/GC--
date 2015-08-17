#include <cstring>
#include <iostream>

class CMyString
{
public:
	CMyString(const char*Data);
	//复制构造函数，copy constructor；用于类初始化
	CMyString(const CMyString& str);
	//赋值操作符，copy assignment operator; 通过传入CMyString实例，返回CMyString类型对象
	CMyString& operator=(const CMyString &str);
	~CMyString(){};

	void Print();   //测试函数
private:
	char* m_pData;
	int m_nNo;
};

CMyString::CMyString(const char* Data)
{
	//特殊值测试，考虑传入指针为空的情况
	if (Data==NULL)
	{
		m_pData=new char[1];
		m_pData[0]='\0';
	}
	else
	{
		m_pData=new char[strlen(Data)+1];
		strcpy(m_pData,Data);
	}
}

CMyString::CMyString(const CMyString& str)
{
	m_pData=new char(strlen(str.m_pData)+1);
	strcpy(m_pData,str.m_pData);
}

CMyString& CMyString::operator =(const CMyString &str)
{
	//通过地址来判断是不是同一实例
	if (this==&str)   
	{
		return *this;
	}

	//释放实例本身已有内存，防止内存泄露；置为NULL，防止悬挂指针
	delete []m_pData;
	m_pData = NULL; 

	m_pData=new char(strlen(str.m_pData)+1);
	strcpy(m_pData,str.m_pData);

	return *this;
}

CMyString::~CMyString()
{
	delete[] m_pData;
}

// ====================测试代码====================
void CMyString::Print()
{
	cout<<m_pData<<endl;
}

void Test()
{
	CMyString Emp("hello");	 //构造函数测试

	char* temp="yes girl";
	CMyString Emp1(temp);   //复制构造函数

	CMyString Emp2(Emp);
	CMyString Emp3=Emp1;	//copy assignment

	Emp.Print();
	Emp1.Print();
	Emp2.Print();
	Emp3.Print();
}

int main()
{
	Test();
	return 0;
}

