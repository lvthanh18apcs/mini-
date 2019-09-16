
#include "Header.h"

void SLL::Display()
{
	Node* temp = root;
	while (temp != nullptr)
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
	if (root == nullptr)
	{
		root = new Node;
		root->data = x;
		return;
	}
	Node* a = new Node;
	a->data = x;
	Node* run = root;
	while (run->next != nullptr) run = run->next;
	run->next = a;
}

void SLL::InsertBegin(int& x)
{
	Node* temp; temp = new Node;
	temp->data = x;
	temp->next = root;
	root = temp;
}

bool SLL::DeleteAnode(int x)
{
	Node* temp = root;
	while (temp != nullptr)
	{
		if (temp->data == x)
		{
			Node* camp = temp->next;
			root = camp;
			return true;
		}
		else if (temp->next->data == x)
		{
			Node* camp = temp->next;
			temp->next = camp->next;
			Node* a = root; temp = a;
			root = temp;
			return true;
		}
		else temp = temp->next;
	}
	return false;
}

void Problem1()
{
	int n = 1;
	cout << "N\t" << "10*N\t" << "100*N" << endl;
	while (n <= 4)
	{
		cout << n << "\t" << 10 * n << "\t" << 100 * n;
		cout << endl;
		++n;
	}
}

void Problem2()
{
	int a; cin >> a;
	for (int i = 1; i <= 2*a-1; ++i)
	{
		if (i % 2 != 0)
		{
			if (i == 1 || i == 2 * a - 1) for (int j = 0; j < a; ++j) cout << "*";
			else for (int j = 0; j < a; ++j)
			{
				if (j == 0 || j == a - 1) cout << "*";
				else cout << " ";
			}
		}
		else cout << " ";
		cout << endl;
	}
}

void Problem3()
{
	int a, b, c;  cin >> a >> b >> c; int max = a;
	if (b >= max && b >= c)
	{
		max = b;
		if (b < a + c) cout << "YES\n";
		else cout << "NO\n";
	}
	else if (c >= max && c >= b)
	{
		max = c;
		if (c < a + b) cout << "YES\n";
		else cout << "NO\n";
	}
	else 
	{
		if (a < b + c) cout << "YES\n";
		else cout << "NO\n";
	}
}

void Problem4()
{
	int d, m, y,x = 28; cout << "Input date:";
	cin >> d >> m >> y;
	if (y % 100 == 0)
	{
		if (y % 400 == 0) x = 29;
	}
	else if (y % 4 == 0) x = 29;
	if (m <= 7)
	{
		if (m == 2 && d <= x) cout << d << "-" << m << "-" << y << "is a valid date\n";
		else if (m % 2 != 0 && d <= 31) cout << d << "-" << m << "-" << y << "is a valid date\n";
		else if (m % 2 == 0 && d <= 30 && m != 2) cout << d << "-" << m << "-" << y << "is a valid date\n";
		else cout << d << "-" << m << "-" << y << "is an INvalid date\n";
	}
	else if (m > 7)
	{
		if (m % 2 == 0 && d <= 31) cout << d << "-" << m << "-" << y << "is a valid date\n";
		else if (m % 2 != 0 && d <= 30) cout << d << "-" << m << "-" << y << "is a valid date\n";
		else cout << d << "-" << m << "-" << y << "is an INvalid date\n";
	}
}

void Problem5()
{
	float input, output; cout << "Input electricity unit: "; cin >> input;
	if (input <= 50)
	{
		output = input * 0.5;
		cout << "Total electricity bill :" << output << endl;
	}
	else
	{
		output = 50 * 0.5;
		input -= 50;
		if (input <= 100)
		{
			output += input * 0.75;
			cout << "Total electricity bill :" << output << endl;
		}
		else
		{
			output += 100 * 0.75;
			input -= 100;
			if (input <= 100)
			{
				output += input * 1.2;
				cout << "Total electricity bill:" << output << endl;
			}
			else
			{
				output += 100 * 1.2;
				input -= 100;
				if (input > 0)
				{
					output += input * 1.5;
					cout << "Total electricity bill:" << output << endl;
				}
				else cout << "Total electricity bill:" << output << endl;
			}
		}
	}
}
