#include "CFileThrowEx.h"


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
	try {
		delete pf_file;
		pf_file = fopen(sFileName.c_str(), "w+");
	}
	catch (int e) {
		cout << "An exception # " << e << '\n'; 
	}

}

void CFileThrowEx::vCloseFile()
{
	try {
		fclose(pf_file);
	}
	catch (int e) {
		cout << "An exception # " << e << '\n';
	}	
}

void CFileThrowEx::vPrintLine(string sText)
{
	try {
		fprintf(pf_file, sText.c_str());
	}
	catch (int e) {
		cout << "An exception # " << e << '\n';
	}
}

void CFileThrowEx::vPrintManyLines(vector<string> sText)
{
	try {
		for (string s : sText) {
			vPrintLine(s);
		}
	}
	catch (int e) {
		cout << "An exception # " << e << '\n';
	}

}
