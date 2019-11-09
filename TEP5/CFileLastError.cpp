#include "CFileLastError.h"
#include <iostream>
using namespace std;
#pragma warning (disable : 4996)

CFileLastError::CFileLastError()
{
	b_last_error = false;
	this->pf_file = NULL;
}

CFileLastError::CFileLastError(string sFileName)
{
	b_last_error = false;
	pf_file = fopen(sFileName.c_str(), "w+");
	if (pf_file != NULL)
		cout << "asdsa" << endl;
}

CFileLastError::~CFileLastError()
{
	if (pf_file != NULL)
		vCloseFile();
}

void CFileLastError::vOpenFile(string sFileName)
{
	b_last_error = false;
	if (pf_file == NULL)
	{
		b_last_error = true;
		return;
	}
	//delete pf_file;
	pf_file = fopen(sFileName.c_str(), "w+");
}

void CFileLastError::vCloseFile()
{
	b_last_error = false;
	if (pf_file == NULL)
	{
		b_last_error = true;
		return;
	}
	fclose(pf_file);
}

void CFileLastError::vPrintLine(string sText)
{
	b_last_error = false;
	if (pf_file == NULL)
	{
		b_last_error = true;
		return;
	}
	fprintf(pf_file, sText.c_str());
}

void CFileLastError::vPrintManyLines(vector<string> sText)
{
	b_last_error = false;
	if (pf_file == NULL)
	{
		b_last_error = true;
		return;
	}
	for (int ii = 0; ii < sText.size(); ii++)
		vPrintLine(sText[ii]);
}