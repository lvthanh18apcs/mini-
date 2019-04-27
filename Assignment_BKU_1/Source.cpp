
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
	for (int i=0;i<n;++i)
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

		in.get(x[i].date, 11, '\n');
		in.ignore(1000,'\n');
	}
	in.close();
}

