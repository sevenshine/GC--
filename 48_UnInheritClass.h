#pragma once
#include <iostream>

class UnInheritClass
{
public:
	static UnInheritClass* GetIntance()
	{
		return new UnInheritClass;
	}
	static void DeleteInstance(UnInheritClass* pInstance)
	{
		delete pInstance;
	}

private:
	UnInheritClass();
	~UnInheritClass();
};
