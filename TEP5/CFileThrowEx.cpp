#include "CFileThrowEx.h"
#pragma warning (disable : 4996)

/*
	Errors list:
	-1: File is not implemented
	-2: There is no file's type
*/

CFileThrowEx::CFileThrowEx()
{
	pf_file = NULL;
}

CFileThrowEx::CFileThrowEx(string sFileName)
{
	vOpenFile(sFileName);
}


CFileThrowEx::~CFileThrowEx()
{
	vCloseFile();
}

void CFileThrowEx::vOpenFile(string sFileName)
{
	try
	{
		if (sFileName.rfind(".") == string::npos)
		{
			throw - 2;
		}
		pf_file = fopen(sFileName.c_str(), "w+");
		if (pf_file == NULL)
			throw - 1;
	}
	catch (int e)
	{
		cout << "An exception # " << e << '\n';
	}
}

void CFileThrowEx::vCloseFile()
{
	try
	{
		if (pf_file == NULL)
			throw - 1;
		else {
			fclose(pf_file);
			pf_file = NULL;
		}
	}
	catch (int e)
	{
		cout << "An exception # " << e << '\n';
	}
}

void CFileThrowEx::vPrintLine(string sText)
{
	try
	{
		if (pf_file == NULL)
			throw - 1;
		fprintf(pf_file, sText.c_str());
	}
	catch (int e)
	{
		cout << "An exception # " << e << '\n';
	}

}

void CFileThrowEx::vPrintManyLines(vector<string> sText)
{
	for (int i = 0; i < sText.size(); i++)
		vPrintLine(sText[i]);

}