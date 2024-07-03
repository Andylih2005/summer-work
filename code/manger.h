#pragma once
#include<iostream>
#include"book.h"
using namespace std;
struct manger
{
	string idname;//用户名
	string password;//密码
	manger* next;
	manger(string id,string pw):idname(id),password(pw)
	{
		next = NULL;
	}
	manger()
	{
		idname = "";
		password = "";
		next = NULL;
	}
	void addbook(string name,string type,string id,int number,string author,string press);
	void editbook( string name, string type, string id, int number, string author, string press);
	void delbook(string name, string type, string id, int number, string author, string press);
	void changenum(string id, int num);
};
struct savemanger
{
	manger* head;
	savemanger()
	{
		head = new manger();
	}
	void addmanger(manger* nm)
	{
		nm->next = head->next;
		head->next = nm;
	}
	void delmanger(string id)
	{
		manger* rear = head;
		while (rear->next != NULL)
		{
			if (rear->next->idname == id)
			{
				manger* tmp = rear->next;
				rear->next = tmp->next;
				delete tmp;
			}
		}
	}
};
void makemanger(string idname, string password,savemanger &db)
{
	manger* tmp = new manger(idname, password);
	db.addmanger(tmp);
}
void loginmanger(string idname, string password,savemanger &db)
{
	bool flag = false;
	manger* rear = db.head->next;
	while (rear != NULL)
	{
		if (rear->idname == idname && rear->password==password)
		{
			flag = true;
			cout << "管理員登入成功"<<endl;
		}
		rear = rear->next;
	}
	if (!flag)
	{
		cout << "管理員賬號或密碼有誤"<<endl;
	}
}
