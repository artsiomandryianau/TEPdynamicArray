#ifndef CTABLE_H
#define CTABLE_H

using namespace std;

#define DEBUG true
#define INITIAL_SIZE 10
#define INITIAL_NAME "new array"

class CTable
{
public:
	CTable();
	CTable(string sName, int iTableLen);
	CTable(CTable &sourceCTable);
	~CTable();

	CTable operator+(CTable& pcNewVal);
	CTable operator+=(CTable& pcNewVal);
	CTable operator+=(int number);


	string getName();
	int getSize();
	int* getArray();
	void vSetName(string sName);
	bool bSetNewSize(int newSize);
	bool vSetValueAt(int cellNumber, int value);
	int vGetValue(int cellNumber);
	CTable* clone();
	void copyParameters(CTable &sourceArray);
	string vGetInfo();
	string sGetString();
	void v_mod_tab(CTable *pcTab, int iNewSize);
	void v_mod_tab(CTable cTab, int iNewSize);
	bool bCheckErr(int iCheackable);
	bool bCheckErrForNewTable(int iCheackable);

private:
	string s_name;
	int size;
	int* piTable;
};

#endif