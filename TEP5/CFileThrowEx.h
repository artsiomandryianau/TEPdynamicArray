#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

class CFileThrowEx
{
public:
	CFileThrowEx();
	CFileThrowEx(string sFileName);
	~CFileThrowEx();

	void  vOpenFile(string sFileName);
	void  vCloseFile();
	void  vPrintLine(string sText);
	void  vPrintManyLines(vector<string> sText);
private:
	FILE  *pf_file;
};