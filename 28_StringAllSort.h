#pragma once
#include <iostream>
using namespace std;

void StringSort(char* pStr)
{
	if (pStr==NULL)
		return;

	StringSort(pStr, pStr);
}

void StringSort(char* pStr, char* pBegin)
{
	if (*pBegin=='\0')
	{
		printf("%s\n",pStr);
	}
	else
	{
		for (char* pCh=pBegin; *pCh!='\0'; ++pCh)
		{
			int temp=*pCh;
			*pCh=*pBegin;
			*pBegin=temp;

			StringSort(pStr, pBegin+1);

			temp=*pCh;
			*pCh=*pBegin;
			*pBegin=temp;
		}
	}
}