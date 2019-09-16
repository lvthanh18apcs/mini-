#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>

using namespace std;

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
	void InsertBegin(int& x);
	bool DeleteAnode(int x);
	~SLL();
};
void Problem1();
void Problem2();
void Problem3();
void Problem4();
void Problem5();
