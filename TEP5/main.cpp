#include <iostream>
#include "CTable.h"
#include "CFileErrCode.h"
#include "CFileLastError.h"
#include "CFileThrowEx.h"

int main()
{
	CFileThrowEx cfte;
	cfte.vOpenFile("CFTE_Text.txt");
	cfte.vPrintLine("F");
	cfte.vCloseFile();
	cfte.vCloseFile();

	CFileErrCode cfec;
	cfec.bOpenFile("CFEC_Text.txt");
	cfec.bPrintLine("F");
	cfec.bCloseFile();
	cout << cfec.bCloseFile() << endl;

	CFileLastError cfle;
	cfle.vOpenFile("CFLE_Text.txt");
	cfle.vPrintLine("F");
	cfle.vCloseFile();
	cfle.vCloseFile();
	cout << cfle.bGetLastError() << endl;

	system("pause");
	return 0;
}
