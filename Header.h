#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

struct node
{
	int data = 0;
	node* next = nullptr;
	node* branch = nullptr;
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
	bool DeleteLastX(int x);
	bool EditAllX(int x,int key);
};
 
class sll
{
private:
	node* root = nullptr;
public:
	void Display();
	void InsertLast(int x);
	void InsertBegin(int x);
	bool InsertTagX(int key, int x);
};

void SingleBranch();
void MultipleBranch();