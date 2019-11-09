#include "CFileErrCode.h"


CFileErrCode::CFileErrCode()
{
	pf_file = NULL;
}

CFileErrCode::CFileErrCode(string sFileName)
{
	bOpenFile(sFileName);
}


CFileErrCode::~CFileErrCode()
{
	bCloseFile();
}

bool CFileErrCode::bOpenFile(string sFileName)
{
	if (pf_file != NULL) {
		delete pf_file;
		pf_file = fopen(sFileName.c_str(), "w+");
		return true;
	}
	else {
		return false;
	}	
}

bool CFileErrCode::bCloseFile()
{
	if (pf_file != NULL) {
		fclose(pf_file);
		return true;
	}
	else {
		return false;
	}
}

bool CFileErrCode::bPrintLine(string sText)
{
	if (pf_file != NULL) {
		fprintf(pf_file, sText.c_str());
		return true;
	}
	else {
		return false;
	}
}

bool CFileErrCode::bPrintManyLines(vector<string> sText)
{
	if (pf_file != NULL) {
		for (string s : sText) {
			bPrintLine(s);
		}
		return true;
	}
	else {
		return false;
	}
}
