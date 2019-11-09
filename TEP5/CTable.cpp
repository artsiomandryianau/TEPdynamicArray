#include "CTable.h"
#include <string>

CTable::CTable()
{
	sName = CONST_NAME;
	piTable = new int[CONST_SIZE];
	iSize = CONST_SIZE;
	cout << "Bezp: " << sName << endl;
}

CTable::CTable(string s_Name, int iTableLen)
{
	this->vSetName(s_Name);
	this->bSetNewSize(iTableLen);
	cout << "Parametr: " << sName << endl;
}

CTable::CTable(const CTable& pcOther)
{
	sName = pcOther.sName + "_copy";
	iSize = pcOther.iSize;
	piTable = new int[pcOther.iSize];
	for (int ii = 0; ii < iSize; ii++)
	{
		piTable[ii] = pcOther.piTable[ii];
	}
	cout << "Kopuj: " << sName << endl;
}

void CTable::vSetName(string s_Name)
{
	sName = s_Name;
}

bool CTable::bSetNewSize(int iTableLen)
{

	if (!bCheckErrForNewTable(iTableLen))
		return false;

	int* pi_newTable = new int[iTableLen];


	if (iSize < iTableLen)
	{
		for (int ii = 0; ii < iSize; ii++)
		{
			pi_newTable[ii] = piTable[ii];
		}
	}
	else
	{
		for (int ii = 0; ii < iTableLen; ii++)
		{
			pi_newTable[ii] = piTable[ii];
		}
	}
	delete piTable;
	iSize = iTableLen;
	piTable = pi_newTable;
	return true;
}

CTable* CTable::pcClone() {
	CTable* copy = new CTable(sName, iSize);
	return copy;
}

CTable CTable::operator+(CTable& pcNewVal)
{
	int newSize = pcNewVal.iSize + iSize;
	int* piTableNew = new int[newSize];
	for (int ii = 0; ii < iSize; ii++)
	{
		piTableNew[ii] = piTable[ii];
	}
	for (int ii = iSize; ii < newSize; ii++)
	{
		piTableNew[ii] = pcNewVal.piTable[ii - iSize];
	}
	delete piTable;
	piTable = piTableNew;
	iSize = newSize;
	sPassword = sPassword + pcNewVal.sPassword;
	return *this;
}

CTable CTable::operator*(CTable& pcNewVal)
{
	int iCounter = 0;
	for (int ii = 0; ii < this->iSize; ii++)
	{
		for (int iz = 0; iz < pcNewVal.iSize; iz++)
		{
			if (piTable[ii] == pcNewVal.piTable[iz])
			{
				iCounter++;
			}
		}
	}
	int* piTableTmp = new int[iCounter];
	int iFlag = 0;
	for (int ii = 0; ii < this->iSize; ii++)
	{
		for (int iz = 0; iz < pcNewVal.iSize; iz++)
		{
			if (piTable[ii] == pcNewVal.piTable[iz])
			{
				piTableTmp[iFlag++] = piTable[ii];
			}
		}
	}
	delete piTable;
	if (iCounter != 0)
		piTable = piTableTmp;
	else
		piTable = nullptr;
	iSize = iCounter;
	return *this;
}

void CTable::vShowName()
{
	cout << "Name: " << sName << endl;
}

void CTable::vShowSize()
{
	cout << "Size: " << iSize << endl;
}

bool CTable::bCheckErr(int iCheackable)
{
	if (iCheackable < 0)
	{
		cout << "Error, new size must be greater than 0" << endl;
		cout << iCheackable << " is less than 0" << endl;
		return false;
	}
	if (iCheackable == 0)
	{
		cout << "Error, new size must be greater than 0" << endl;
		cout << iCheackable << " is equal to 0" << endl;
		return false;
	}
	return true;
}

bool CTable::bCheckErrForNewTable(int iCheackable)
{
	if (!bCheckErr(iCheackable))
		return false;

	/*if (iCheackable <= iSize)
	{
		cout << "Error, new size must be greater than previous size" << endl;
		cout << iCheackable << " is less than previous size" << endl;
		return false;
	}*/
	if (iCheackable == iSize)
	{
		//cout << "Error, new size must be greater than previous size" << endl;
		cout << "ERROR: " << iCheackable << " is equal to previous size" << endl;
		return false;
	}
	return true;
}

void CTable::v_mod_tab(CTable* pcTab, int iNewSize)
{
	if (!bCheckErrForNewTable(iNewSize))
		return;

	pcTab->bSetNewSize(iNewSize);
}

void CTable::v_mod_tab(CTable cTab, int iNewSize)
{
	if (!bCheckErrForNewTable(iNewSize))
		return;
	cTab.bSetNewSize(iNewSize);
}

void CTable::vSetValueAt(int iOffset, int iNewVal)
{
	if (iOffset >= iSize || iOffset < 0) {
		cout << "Error, value must be less than table's size" << endl;
		cout << iOffset << " is greater than table's size (or equal to)" << endl;
		return;
	}
	piTable[iOffset] = iNewVal;
}

void CTable::vPrint()
{
	for (int ii = 0; ii < iSize; ii++)
	{
		cout << ii << ": " << piTable[ii] << endl;
	}
}

bool CTable::isGoodPassword(string& tmpStr)
{
	cout << "Inserted new password: " << tmpStr << endl;
	int length = tmpStr.length();
	if (length < 6) {
		cout << "Error: not enough symbols" << endl;
		cout << "Need 6 and more, but you have only " << length << " symbols" << endl;
		return false;
	}
	int isUpperCase = 0;
	int isLowerCase = 0;
	int errors = 0;
	for (int i = 0; i < length; i++) {
		int c = tmpStr[i];
		if (islower(c))
			isLowerCase++;
		else if (isupper(c))
			isUpperCase++;
		else
			errors++;
	}
	if (isUpperCase > 0 && isLowerCase > 0 && errors == 0)
		return true;
	else
	{
		if (isUpperCase == 0)
			cout << "Error: must be one and more great letters" << endl;
		if (isLowerCase == 0)
			cout << "Error: must be one and more small letters" << endl;
		if (errors > 0)
			cout << "Error: must be only letters" << endl;
		return false;
	}

}

bool CTable::setPassword(string& tmpStr)
{
	if (isGoodPassword(tmpStr))
	{
		sPassword = tmpStr;
		return true;
	}
	else
		return false;

}

CTable::~CTable()
{
	cout << "Usuwam: " << sName << endl;
	delete piTable;
}
