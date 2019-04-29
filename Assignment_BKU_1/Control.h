#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h>

using namespace std;

struct Customer
{
	char ID[9];
	char name[51], address[201], city[51];
	char phone[13];
	char date[11];
	// phone number : 12 digits
};

struct Transaction
{
	char ID[9]; // 8 digits
	char cusID[9]; // 8 digits
	char type[7]; // 3 types: whole, retail, other
	double value;
	char date[11];
	char IDP[9];
};

struct Product
{
	char ID[9]; // 8 digits
	char name[101], model[101];
	int quantity;
	double price;
};

void Customer_Input(Customer* &x);
void Transaction_Input(Transaction*& y);
void Product_Input(Product*& z);

void main_control();

