#pragma once
#include<iostream>
#include"book.h"
using namespace std;
class manger
{
	string idname;//用户名
	string password;//密码
	manger(string id,string pw):idname(id),password(pw){}
	void addbook(string name,string type,string id,int number,string author,string press);
	void editbook( string name, string type, string id, int number, string author, string press);
	void delbook(string name, string type, string id, int number, string author, string press);
	void changenum(string id, int num);
};
