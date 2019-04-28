#include "Control.h"

void Color(int k)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}

void go(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

void Customer_Input(Customer *x)
{

	ifstream in;
	in.open("Customer.txt");
	int n;
	in >> n;
	x = new Customer[n];
	for (int i = 0; i < n; ++i)
	{
		in.get(x[i].ID, 8, '\n');
		in.ignore(1000, '\n');

		in.get(x[i].name, 50, '\n');
		in.ignore(1000, '\n');

		in.get(x[i].phone, 12, '\n');
		in.ignore(1000, '\n');

		in.get(x[i].address, 200, '\n');
		in.ignore(1000, '\n');

		in.get(x[i].city, 50, '\n');
		in.ignore(1000, '\n');

		in.get(x[i].date, 10, '\n');
		in.ignore(1000, '\n');
	}
	in.close();
}
void Transaction_Input(Transaction *y)
{
	ifstream in;
	in.open("Transaction.txt");
	int n;
	in >> n;
	y = new Transaction[n];
	for (int i = 0; i < n; ++i)
	{
		in.get(y[i].ID, 8, '\n');
		in.ignore(1000, '\n');

		in.get(y[i].cusID, 8, '\n');
		in.ignore(1000, '\n');

		in.get(y[i].type, 6, '\n');
		in.ignore(1000, '\n');

		in.get(y[i].IDP, 8, '\n');
		in.ignore(1000, '\n');

		in >> y[i].value;

		in.get(y[i].date, 10, '\n');
		in.ignore(1000, '\n');
	}
	in.close();
}
void Product_Input(Product *z)
{
	ifstream in;
	in.open("Product.txt");
	int n;
	in >> n;
	z = new Product[n];
	for (int i = 0; i < n; ++i)
	{
		in.get(z[i].ID, 8, '\n');
		in.ignore(1000, '\n');

		in.get(z[i].name, 100, '\n');
		in.ignore(1000, '\n');

		in.get(z[i].model, 100, '\n');
		in.ignore(1000, '\n');

		in >> z[i].quantity;

		in >> z[i].price;


	}
	in.close();
}


