// ParseTime.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "DString.h"
#include "iostream"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int iNum = 0;
	int iAccontId = 0;
	cout << "��������Ҫ��ѯ�ĺ��룺";
	cin >> iNum;
	cout << "������TRGAME�ʺţ������֣�����ҪTR����";
	cin >> iAccontId;
	cout << endl;

	int iTime = iNum ^ iAccontId;
	DString strTime = IntToString(iTime);
	strTime = strTime->reverse();

	cout << "Time : " << strTime->getNativeCharPtr() << endl;
	system("PAUSE");
	return 0;
}

