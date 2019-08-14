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
	bool DeleteAnode(int x);
	~SLL();
};
