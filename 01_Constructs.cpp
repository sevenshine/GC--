#include <cstring>
#include <iostream>

class CMyString
{
public:
	CMyString(const char*Data);
	//���ƹ��캯����copy constructor���������ʼ��
	CMyString(const CMyString& str);
	//��ֵ��������copy assignment operator; ͨ������CMyStringʵ��������CMyString���Ͷ���
	CMyString& operator=(const CMyString &str);
	~CMyString(){};

	void Print();   //���Ժ���
private:
	char* m_pData;
	int m_nNo;
};

CMyString::CMyString(const char* Data)
{
	//����ֵ���ԣ����Ǵ���ָ��Ϊ�յ����
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
	//ͨ����ַ���ж��ǲ���ͬһʵ��
	if (this==&str)   
	{
		return *this;
	}

	//�ͷ�ʵ�����������ڴ棬��ֹ�ڴ�й¶����ΪNULL����ֹ����ָ��
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

// ====================���Դ���====================
void CMyString::Print()
{
	cout<<m_pData<<endl;
}

void Test()
{
	CMyString Emp("hello");	 //���캯������

	char* temp="yes girl";
	CMyString Emp1(temp);   //���ƹ��캯��

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

