#include<iostream>
#include "CTable.h"
#include <string>
//#include <typeinfo>


using namespace std;

CTable::CTable()
{
	s_name = INITIAL_NAME;
	size = INITIAL_SIZE;
	piTable = new int[size];
	if (DEBUG) cout << "bezp: " << s_name << endl;
}

CTable::CTable(string sName, int iTableLen)
{
	s_name = sName;
	size = iTableLen;
	piTable = new int[size];
	if (DEBUG) cout << "parametr: " << s_name << endl;
}

CTable::CTable(CTable &sourceCTable)
{
	s_name = sourceCTable.getName() + "_copy";
	size = sourceCTable.getSize();
	piTable = new int[size];
	for (int i = 0; i < size; i++)
	{
		piTable[i] = sourceCTable.getArray()[i];
	}
	if (DEBUG) cout << "copy: " << s_name << endl;
}

CTable::~CTable()
{
	if (DEBUG) cout << "deleting " << s_name << endl;
	delete[] piTable;
}


string CTable::getName()
{
	return s_name;
}

void CTable::vSetName(string sName)
{
	s_name = sName;
	if (DEBUG) cout << "name changed to: " << sName << endl;
}

int CTable::getSize()
{
	return size;
}

int* CTable::getArray()
{
	return piTable;
}

bool CTable::bSetNewSize(int newSize)
{
	if (newSize < 0)
	{
		if (DEBUG) cout << "ERROR: size cannot be less than 0 " << endl;
		return false;
	}

	size = newSize;
	int* pNewArray = new int[size];

	for (int i = 0; i < size; i++)
	{
		pNewArray[i] = piTable[i];
	}

	delete[] piTable;
	piTable = pNewArray;

	if (DEBUG) cout << "size changed to: " << size << endl;
	return true;
}

bool CTable::vSetValueAt(int cellNumber, int value)
{
	if (cellNumber < 0)
	{
		if (DEBUG) cout << "ERROR: cell size cannot be less than 0 " << endl;
		return false;
	}
	else if (cellNumber >= size)
	{
		if (DEBUG) cout << "ERROR: cell num out of range " << endl;
		return false;
	}

	piTable[cellNumber] = value; //index bigger or equal than array size exists?
	if (DEBUG) cout << "cell no " << cellNumber
		<< " = " << value << endl;
	return true;
}

int CTable::vGetValue(int cellNumber)
{
	if (cellNumber < 0)
	{
		if (DEBUG) cout << "ERROR: cell number can't be less than 0" << endl;
		return 0;
	}
	else if (cellNumber >= size)
	{
		if (DEBUG) cout << "ERROR: cell number out of range!" << endl;
		return 0;
	}
	return piTable[cellNumber];

}

CTable* CTable::clone() //+
{
	CTable *pCloneTable;
	pCloneTable = new CTable();
	pCloneTable->bSetNewSize(size);

	if (DEBUG) cout << "cloning values to the new object" << endl;

	for (int i = 0; i < size; i++)
	{
		pCloneTable->vSetValueAt(i, piTable[i]);
	}

	if (DEBUG) cout << "returning the " << s_name << " clone " << endl;
	return pCloneTable;
}
//returning a variable declared inside a function
//will unable to use the variable outside??

void CTable::copyParameters(CTable &sourceArray)
{
	int copiedSize = sourceArray.getSize();
	bSetNewSize(copiedSize);

	int* copiedArray = sourceArray.getArray();

	for (int i = 0; i < size; i++)
	{
		piTable[i] = copiedArray[i];//why can't I use the arrow op here?
	}

	if (DEBUG) cout << "copied succesfully" << endl;
}

string CTable::vGetInfo()
{
	return s_name + " len: " + to_string(size) + " values: " + sGetString();
}

string CTable::sGetString()
{
	string arrValues;
	int lastComaPos = size - 2;

	for (int i = 0; i < size; i++)
	{
		arrValues += to_string(piTable[i]);
		if (i <= lastComaPos) {
			arrValues += ", ";
		}
	}
	return arrValues;
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
void CTable::v_mod_tab(CTable* pcTab, int iNewSize)
{
	if (!bCheckErrForNewTable(iNewSize))
		return;

	pcTab->bSetNewSize(iNewSize);
}

CTable CTable::operator+(CTable& pcNewVal)
{
	int newSize = pcNewVal.size + this->size;
	int *piNewTable = new int[newSize];
	for (int ii = 0; ii < this->size; ii++)
	{
		piNewTable[ii] = this->piTable[ii];
	}
	for (int ii = this->size; ii < newSize; ii++)
	{
		piNewTable[ii] = pcNewVal.piTable[ii - size];
	}
	CTable CTable;
	CTable.bSetNewSize(newSize);
	CTable.vSetName(this->s_name + pcNewVal.s_name);
	delete CTable.piTable;
	CTable.piTable = piNewTable;
	return CTable;
}

CTable CTable::operator +=(CTable &pcNewVal)
{
	int newSize = pcNewVal.size + size;
	int* piTableNew = new int[newSize];
	for (int ii = 0; ii < size; ii++)
	{
		piTableNew[ii] = piTable[ii];
	}
	for (int ii = size; ii < newSize; ii++)
	{
		piTableNew[ii] = pcNewVal.piTable[ii - size];
	}
	delete piTable;
	piTable = piTableNew;
	size = newSize;
	return *this;

}
CTable CTable::operator+=(int number)
{
	int newSize = 1 + size;
	int* piTableNew = new int[newSize];
	for (int ii = 0; ii < size; ii++)
	{
		piTableNew[ii] = piTable[ii];
	}
	piTableNew[size] = number;
	delete piTable;
	piTable = piTableNew;
	size = newSize;
	return *this;
}

void CTable::v_mod_tab(CTable cTab, int iNewSize)
{
	if (!bCheckErrForNewTable(iNewSize))
		return;
	cTab.bSetNewSize(iNewSize);
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
	if (iCheackable == size)
	{
		//cout << "Error, new size must be greater than previous size" << endl;
		cout << "ERROR: " << iCheackable << " is equal to previous size" << endl;
		return false;
	}
	return true;

}
