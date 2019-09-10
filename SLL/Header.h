#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Node
{
	int data;
	Node* next;
	Node()
	{
		data = 0;
		next = nullptr;
	}
};

class SLL
{
private:	
	Node* root = nullptr;
public:
	void Display();
	void InsertLast(int x);
	void InsertBegin(int x);
	//return true if there is a node x and remove that node from the SLL
	//return false if there is not a node x and do nothing
	bool DeleteAnode(int x);
	//return number of X deleted and remove them from the SLL
	int DeleteAllX(int x);
	//insert key value before and after any node with value x
	//return true if there is at least one x, otherwise return false
	bool InsertBeforeandAfter(int x, int key);
	~SLL();
};
