#pragma once
#include <iostream>
using namespace std;

class CTable
{
public:
	CTable();
	CTable(string sName, int iTableLen);
	CTable(const CTable& pcOther);
	CTable* pcClone();

	string sPassword = "defaultPassword";

	bool isGoodPassword(string& tmpStr);
	bool setPassword(string& tmpStr);

	CTable operator+(CTable& pcNewVal);
	CTable operator*(CTable& pcNewVal);

	string sName;
	int* piTable;
	int iSize;


	void vShowName();
	void vShowSize();
	void vSetName(string sName);
	bool bSetNewSize(int iTableLen);
	bool bCheckErr(int iCheackable);
	bool bCheckErrForNewTable(int iCheackable);
	void v_mod_tab(CTable* pcTab, int iNewSize);
	void v_mod_tab(CTable cTab, int iNewSize);
	void vSetValueAt(int iOffset, int iNewVal);
	void vPrint();
	~CTable();
private:
	int CONST_SIZE = 1;
	string CONST_NAME = "Default";
};

