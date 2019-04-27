#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;

struct Customer
{
	char ID[9];
	char name[50], address[200], city[50];
	char phone[12];
	char date[11];
	// phone number : 12 digits
};

struct Transaction
{
	int ID; // 8 digits
	int cusID; // 8 digits
	int type; // 3 types: whole, retail, other
	double value;
	// remember product detail ??
	char date[10];
};

struct Product
{
	int ID; // 8 digits
	char name[100], model[100];
	int quantity;
	double price;
};

void Customer_Input(Customer* x);
