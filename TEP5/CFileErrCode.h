#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

class CFileErrCode
{
public:

	CFileErrCode();
	CFileErrCode(string sFileName);
	~CFileErrCode();

	bool  bOpenFile(string sFileName);
	bool  bCloseFile();
	bool  bPrintLine(string sText);
	bool  bPrintManyLines(vector<string> sText);

private:
	FILE  *pf_file;
};