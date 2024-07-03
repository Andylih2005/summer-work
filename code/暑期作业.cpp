#include<iostream>
#include<fstream>
#include"manger.h"
#include"reader.h"
#include"sqlite3.h"
using namespace std;
int main()
{
	ifstream in("manger.txt");
	string str;
	string idname, password;
	savemanger dataman;
	while (in >> str)
	{
		idname = str;
		in >> str;
		password = str;
		makemanger(idname, password, dataman);
	}
	in.close();
	ifstream inread("user.txt");
	savereader dataread;
	while (inread >> str)
	{
		idname = str;
		inread >> str;
		password = str;
		makereader(idname, password, dataread);
	}
	inread.close();
	bool run = true;
	while (run)
	{
		cin >> str;
		if (str == "login")
		{
			cout << "reader or manger:";
			cin >> str;
			if (str == "manger")
			{
				cout << "idname:";
				cin >> idname;
				cout << "password:";
				cin >> password;
				loginmanger(idname, password, dataman);
			}
			if (str == "reader")
			{
				cout << "idname:";
				cin >> idname;
				cout << "password:";
				cin >> password;
				loginreader(idname, password, dataread);
			}
		}
		if (str == "makeaccount")
		{
			cout << "reader or manger:";
			cin >> str;
			if (str == "manger")
			{
				cout << "idname:";
				cin >> idname;
				cout << "password:";
				cin >> password;
				makemanger(idname, password, dataman);
			}
			if (str == "reader")
			{
				cout << "idname:";
				cin >> idname;
				cout << "password:";
				cin >> password;
				makereader(idname, password, dataread);
			}
		}
		if (str == "quit")
		{
			run = false;
		}
	}
	ofstream out("manger.txt",ios_base::out);
	manger* rear = dataman.head->next;
	while (rear != NULL)
	{
		out << rear->idname << " " << rear->password << endl;
		rear = rear->next;
	}
	ofstream outread("user.txt", ios_base::out);
	reader* rread = dataread.head->next;
	while (rread != NULL)
	{
		outread << rread->idname << " " << rread->password << endl;
		rread = rread->next;
	}
	return 0;
}
