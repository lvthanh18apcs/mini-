
#include "Control.h"

void setcursor(bool x, DWORD size) // x = 0 : invisible, x = 1 : visible
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	if (size == 0)
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = x;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}

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

void Customer_Input(Customer* &x,int &a)
{
	ifstream in;
	in.open("Customer.txt");
	int n;
	in >> n;
	in.ignore();
	a = n;
	x = new Customer[n];
	for (int i = 0; i < 4; ++i)
	{
		in.get(x[i].ID, 9, '\n');
		in.ignore(1000, '\n');

		in.get(x[i].name, 51, '\n');
		in.ignore(1000, '\n');

		in.get(x[i].phone, 13, '\n');
		in.ignore(1000, '\n');

		in.get(x[i].address, 201, '\n');
		in.ignore(1000, '\n');

		in.get(x[i].city, 51, '\n');
		in.ignore(1000, '\n');

		in.get(x[i].date, 11, '\n');
		in.ignore(1000, '\n');
	}
	in.close();
}

void Transaction_Input(Transaction* &y,int &b)
{
	ifstream in;
	in.open("Transaction.txt");
	int n;
	in >> n;
	in.ignore();
	b = n;
	y = new Transaction[n];
	for (int i = 0; i < n; ++i)
	{
		in.get(y[i].ID, 9, '\n');
		in.ignore(1000, '\n');

		in.get(y[i].cusID, 9, '\n');
		in.ignore(1000, '\n');

		in.get(y[i].type, 7, '\n');
		in.ignore(1000, '\n');

		in.get(y[i].IDP, 9, '\n');
		in.ignore(1000, '\n');

		in >> y[i].value;
		in.ignore();

		in.get(y[i].date, 11, '\n');
		in.ignore(1000, '\n');
	}
	in.close();
}

void Product_Input(Product* &z,int &c)
{
	ifstream in;
	in.open("Product.txt");
	int n;
	in >> n;
	in.ignore();
	c = n;
	z = new Product[n];
	for (int i = 0; i < n; ++i)
	{
		in.get(z[i].ID, 9, '\n');
		in.ignore(1000, '\n');

		in.get(z[i].name, 101, '\n');
		in.ignore(1000, '\n');

		in.get(z[i].model, 101, '\n');
		in.ignore(1000, '\n');

		in >> z[i].quantity;

		in >> z[i].price;
		in.ignore();
	}
	in.close();
}

int Display()
{
	int key;
	Color(10);
	system("cls");
	cout << "... Subtask 1..., press 1" << endl;// type subtask here
	cout << "... Subtask 2..., press 2" << endl;
	cout << "... Subtask 3..., press 3" << endl;
	cout << "... Subtask 4..., press 4" << endl;
	cout << "... Subtask 5..., press 5" << endl;
	cout << "To exit program, press Esc" << endl;
	key = _getch();
	if (key == 49)
	{
		Color(7);
		return 1;
	}
	else if (key == 50)
	{
		Color(7);
		cout << "Add fucntions for subtask 2" << endl;
		return 2;
	}
	else if (key == 51)
	{
		Color(7);
		cout << "Add fucntions for subtask 3" << endl;
		return 3;
	}
	else if (key == 52)
	{
		Color(7);
		cout << "Add fucntions for subtask 4" << endl;
		return 4;
	}
	else if (key == 53)
	{
		Color(7);
		cout << "Add fucntions for subtask 5" << endl;
		return 5;
	}
	else if (key == 27)
	{
		Color(7);
		return 0;
	}
	Color(7);
	return -1;
}

bool Login()
{
	go(31, 14);
	Color(12);
	bool c = false;
	int i = 0;
	int x, k = -1; char password[43];
	string keypass = "Oliver";
	password[42] = '\0';
	while (c == false)
	{
		go(20, 14);
		cout << "Password: (" << 5-i << " attemps left): ";
		setcursor(1, 10);
		x = _getch();
		while (1 != 0)
		{
			if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122))
			{
				cout << '*';
				if (k + 1 == 42) break;
				++k;
				password[k] = x;
			}
			else if (x == 8)
			{
				cout << '\b';
				cout << ' ';
				cout << '\b';
				if (k != -1)
				{
					password[k] = '\0';
					--k;
				}
			}
			else if (x == 13) break;

			x = _getch();
		}
		setcursor(0, 0);
		password[k + 1] = '\0';
		if (strlen(password) == keypass.length())
		{
			int n = strlen(password);
			for (int i = 0; i < n; ++i)
				if (password[i] != keypass[i])
					break;
			c = true;
		}
		go(0,14);
		for (int r = 0; r <= 120; ++r)
			cout << " ";
		++i;
		if (i > 4) break;
		k = -1;
	}
	if (c == true)
	{
		for (int i = 0; i < 45; ++i)
		{
			Color((i + 15) % 15);
			go(47, 14);
			cout << "ACCESS GRANTED";
			Sleep(50);
		}
		return true;
	}
	else
	{
		Color(4);
		go(47, 15);
		cout << "ACCESS DENIED!!!";
		return false;
	}
	Color(15);
}

bool Splashscreen()
{
	setcursor(0, 0);
	go(47, 12);
	Color(6);
	cout << "LOADING... ";
	for (int i = 0; i < 51; ++i)
	{
		go(60, 12);
		Color(6);
		if (i * 2 == 100) cout << "99%";
		else 
			cout << i * 2 << "%";
		Color(144);
		go(31 + i, 8);
		cout << " ";
		go(31 + i, 9);
		cout << " ";
		Sleep(50);
	}
	bool y = Login();
	if (y == true)
	{
		go(60, 12);
		Color(6);
		cout << "100%";
		Sleep(300);
		return true;
	}
	setcursor(1, 10);
	Color(15);
	return false;
}

void Subtask1(Customer* x, Transaction* y,int a,int b)
{
	cout << endl;
	double maxv = 0;
	for (int i = 0; i < b; ++i)
	{
		if (y[i].value > maxv) maxv = y[i].value; // find the maximum value of all transaction
	}
	int* save = new int[a];
	for (int i = 0; i < a; ++i)
		save[i] = 0;
	for (int i = 0; i < b; ++i) // find the customer with most transactions with most value
	{
		if (y[i].value == maxv)
		{
			char temp[9];
			strcpy_s(temp, y[i].cusID);
			for (int j = 0; j < a; ++j)
			{
				if (strcmp(temp, x[j].ID) == 0)
				{
					++save[j];
					break;
				}
			}
		}
	}
	int res = 0;
	for (int i = 0; i < a; ++i) // summmarize
		if (save[i] > res) res = save[i];
	for (int i = 0; i < a; ++i) // printing
	{
		if (save[i] == res)
		{
			cout << "Customer's ID: " << x[i].ID << endl;
			cout << "Customer's name: " << x[i].name << endl;
			cout << "Customer's phone: " << x[i].phone << endl;
			cout << "Customer's address: " << x[i].address << endl;
			cout << "Customer's city: " << x[i].city << endl;
			cout << "Customer's day of transaction: " << x[i].date << endl;
			cout << endl << endl;
		}
	}
	system("pause");
	delete[]save;
}

void main_control()
{
	bool y = Splashscreen();
	if (y == true)
	{
		int a = 0, b = 0, c = 0;
		Customer* x = nullptr;
		Transaction* y = nullptr;
		Product* z = nullptr;
		system("cls");
		Color(7);
		cout << "Inputting data...";
		Customer_Input(x, a);
		Transaction_Input(y, b);
		Product_Input(z, c);
		Sleep(1000);
		int t;
		t = Display();
		while (t != 0)
		{
			if (t == 1) Subtask1(x, y, a, b);
			t = Display();
		}
		delete[]x;
		delete[]y;
		delete[]z;
	}
}