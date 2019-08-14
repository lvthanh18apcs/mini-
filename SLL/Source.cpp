
#include "Header.h"

void SLL::Display()
{
	Node* temp = root;
	while (temp)
	{
		std::cout << temp->data << ' ';
		temp = temp->next;
	}
}

SLL::~SLL()
{
	if (root == nullptr) return;
	delete root;
}

void SLL::InsertLast(int x)
{

}

void SLL::InsertBegin(int x)
{

}

bool SLL::DeleteAnode(int x)
{
	return false;
}