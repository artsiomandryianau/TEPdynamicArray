#include <iostream>
#include "CTable.h"
#include "CFileErrCode.h"
#include "CFileLastError.h"
#include "CFileThrowEx.h"

int main()
{
	int kirill = 41;
	string file = "file.txt";
	string g;
	if (kirill == 41) {

		CFileLastError cfle("textCFLE.txt");
		cfle.vPrintLine("asda");
		cfle.vPrintManyLines({ "Huy", "pizda", "Jigurda" });


		CFileLastError bezParamCfle;
		bezParamCfle.vPrintLine("as");
		cout << bezParamCfle.bGetLastError() << endl;
		cfle.vCloseFile();
		cout << cfle.bGetLastError() << endl;

		CFileErrCode cfec("textCFEC.txt");
		cfec.bPrintLine("asda");
		cfec.bPrintManyLines({ "Huy", "pizda", "Jigurda" });


		CFileErrCode bezParamCFEC;
		cout << bezParamCFEC.bPrintLine("ass") << endl;
		cout << cfec.bCloseFile() << endl;

		CFileThrowEx cftc("textCFTC.txt");
		cftc.vPrintLine("ASDADDDD");

		CFileThrowEx bezParamCFTC;
		bezParamCFTC.vPrintLine("saS");
		cftc.vCloseFile();

	}
	system("pause");
	return 0;
}
