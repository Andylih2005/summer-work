#pragma once
#include<iostream>
using namespace std;
struct reader
{
	string idname;
	string password;
	reader* next;
	reader()
	{
		idname = "";
		password = "";
		next = NULL;
	}
	reader(string idname,string password)
	{
		this->idname = idname;
		this->password = password;
		next = NULL;
	}
	void borrowbook();
	void givebackbook();
};
struct savereader
{
	reader* head;
	savereader()
	{
		head = new reader();
	}
	void addreader(reader* rr)
	{
		rr->next = head->next;
		head->next = rr;
	}
};
void makereader(string idname, string password,savereader &db)
{
	reader* tmp = new reader(idname, password);
	db.addreader(tmp);
}
void loginreader(string idname, string password, savereader &db)
{
	bool flag = false;
	reader* rear = db.head->next;
	while (rear != NULL)
	{
		if (rear->idname == idname && rear->password == password)
		{
			flag = true;
			cout << "�Τ�n�J���\" << endl;
		}
		rear = rear->next;
	}
	if (!flag)
	{
		cout << "�Τ�㸹�αK�X���~" << endl;
	}
}