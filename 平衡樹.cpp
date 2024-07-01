#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct treenode
{
	string data;
	bool bl, rl;
	treenode* left;
	treenode* right;
	treenode()
	{
		left = NULL;
		right = NULL;
		bl = true;
		rl = true;
		data = "";
	}
	treenode(string i)
	{
		left = NULL;
		right = NULL;
		bl = true;
		rl = true;
		data = i;
	}
};
struct tree
{
	treenode* root;
	tree(string n)
	{
		root = new treenode(n);
	}
	void display(treenode* dis)
	{
		if (dis != NULL)
		{
			cout << dis->data << " ";
			display(dis->left);
			display(dis->right);
		}
	}
};
struct sq
{
	int f, r;
	treenode** save;
	sq()
	{
		f = -1;
		r = -1;
		save = new treenode*[1500];
	}
	void put(treenode* temp)
	{
		r = (r + 1) % 1500;
		save[r] = temp;
	}
	void pop()
	{
		f = (f + 1) % 1500;
	}
	treenode* getdata()
	{
		return save[(f + 1) % 1500];
	}
};
int height(treenode* tt,bool &b)
{
	if (tt == NULL || tt->data == "null")
		return 0;
	int left = height(tt->left, b) + 1;
	int right = height(tt->right, b) + 1;
	if (abs(left - right) > 1)
	{
		b = false;
	}
	if (left > right)
		return left;
	return right;
}
int main()
{
	ifstream infile("in.txt");
	ofstream outfile("out.txt");
	string str;
	getline(infile, str);
	int len = str.size();
	string temp = "";
	int count = 0;
	sq s;
	tree t("");
	//cout << str << endl;
	for (int i = 1; i < len - 1; i++)
	{
		if (str[i] == ' ')
		{
			if (count == 0)
			{
				t.root->data = temp;
				count++;
				s.put(t.root);
				temp = "";
			}
			else
			{
				treenode* tt = s.getdata();
				if (tt->bl)
				{
					tt->left = new treenode(temp);
					s.put(tt->left);
					tt->bl = false;
					temp = "";
				}
				else
				{
					tt->right = new treenode(temp);
					s.put(tt->right);
					tt->rl = false;
					s.pop();
					temp = "";
				}
			}
		}
		else
		{
			temp = temp + str[i];
		}
	}
	bool ans = true;
	height(t.root, ans);
	if (ans)
	{
		outfile << "True";//SB
	}
	else
	{
		outfile << "False";
	}
}
