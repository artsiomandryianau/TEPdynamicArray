#include "CFileErrCode.h"
#pragma warning (disable : 4996)

CFileErrCode::CFileErrCode()
{
	pf_file = NULL;
}

CFileErrCode::CFileErrCode(string sFileName)
{
	if (sFileName.rfind(".") == string::npos)
	{
		throw - 1;
	}
	pf_file = fopen(sFileName.c_str(), "w+");
}

CFileErrCode::~CFileErrCode()
{
	if (pf_file != NULL)
		bCloseFile();
}

bool CFileErrCode::bOpenFile(string sFileName)
{
	if (pf_file == NULL)
		return false;
	delete pf_file;
	pf_file = fopen(sFileName.c_str(), "w+");
	return true;
}

bool CFileErrCode::bCloseFile()
{
	if (pf_file == NULL)
		return false;

	fclose(pf_file);
	pf_file = NULL;
	return true;
}

bool CFileErrCode::bPrintLine(string sText)
{
	if (pf_file == NULL)
		return false;

	fprintf(pf_file, sText.c_str());
}

bool CFileErrCode::bPrintManyLines(vector<string> sText)
{
	if (pf_file == NULL)
		return false;
	for (int ii = 0; ii < sText.size(); ii++)
		bPrintLine(sText[ii]);
}