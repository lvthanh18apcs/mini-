
#include "Header.h"

void SLL::Display()
{
	Node* temp = root;
	while (temp)
	{
		std::cout << temp->data << ' ';
		temp = temp->next;
	}
	cout << endl;
}

SLL::~SLL()
{
	if (root == nullptr) return;
	delete root;
}

void SLL::InsertLast(int x) //1
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

void SLL::InsertBegin(int x) //2
{
	Node* temp; temp = new Node;
	temp->data = x;
	temp->next = root;
	root = temp;
}

bool SLL::DeleteAnode(int x) //3
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

bool SLL::InsertBeforeandAfter(int x, int key) //4
{
	Node* temp = new Node; bool check = false; int count = 0;
	temp->next = root;
	while (temp->next != nullptr)
	{
		if (temp->next->data == key && count == 0)  // 9 1 3
		{
			check = true; count = 1;
			Node* camp = temp;
			camp->data = x;
			Node* A = new Node;
			A->data = x; A->next = camp->next->next;
			camp->next->next = A;
			temp = camp; root = temp;
		}
		else if (temp->next->data == key && count != 0)
		{
			Node* camp = new Node;
			camp->data = x; camp->next = temp->next;
			Node* A = new Node;
			A->data = x; A->next = temp->next->next;
			camp->next->next = A; temp->next = camp;
			Node* b = temp; Node* a = root; 
			b = a; root = b; temp = temp->next;
		}
		temp = temp->next;
	}
	if (check == true) return true;
	else return false;
}

int SLL::DeleteAllX(int x) //5
{
	int sum = 0; 
	Node* temp = root;
	if (temp->next == nullptr && temp->data == x)
	{
		++sum;
		temp = nullptr;
		goto label;
	}
	while (temp->next != nullptr)
	{
		if (temp->data == x )
		{
			Node* camp = temp->next;
			root = camp;
			++sum; temp = temp->next;
		}								// 1
		else if (temp->next->data == x ) // 3 1 1 1 3
		{
			Node* camp = temp->next;
			temp->next = camp->next;
			Node* a = root; temp = a;
			root = temp;
			++sum; 
		}
		else temp = temp->next;
	}
label:
	return sum;
}

bool SLL::DeleteLastX(int x) //6
{
	int count= 0 ,check = 0;
	Node* temp = root;
	if (temp->next == nullptr && temp->data == x)
	{
		++count;
		temp = nullptr;
		goto label;
	}
	while (temp != nullptr)
	{
		if (temp->data == x) ++count;
		temp = temp->next;
	}
	temp = root;
	while (temp->next != nullptr)
	{
		if (temp->next->data == x) ++check;
		if (temp->data == x && count == 1)
		{
			Node* camp = temp->next;
			root = camp;
			temp = temp->next;
		}								// 1
		else if (temp->next->data == x && check == count) // 3 1 1 1 3
		{
			Node* camp = temp->next;
			temp->next = camp->next;
			Node* a = root; temp = a;
			root = temp; 
		}
		else temp = temp->next;
	}
label:
	if (count > 0) return true;
	else return false;
}

bool SLL::EditAllX(int x,int key) //7
{
	Node* temp = root; bool check = false;
	if (temp->next == nullptr && temp->data == key)
	{
		check = true;
		temp->data = x;
		goto label;
	}
	while (temp->next != nullptr)
	{
		if (temp->data == key && check == false)
		{
			check = true;
			temp->data = x;
		}
		else if (temp->next->data == key)
		{
			check = true;
			temp->next->data = x;
		}
		else temp = temp->next;
	}
label:
	if (check == true) return true;
	else return false;
}
void sll::Display()
{
	node* temp = root;
	while (temp)
	{
		std::cout << temp->data << ' ';
		if (temp->branch != nullptr)
		{
			node* camp = temp->branch;
			while (camp != nullptr)
			{
				std::cout << "( " << temp->branch->data << ' ';
				camp = camp->next;
			}
			cout << ") ";
		}
		temp = temp->next;
	}
	cout << endl;
}
void sll::InsertLast(int x)
{
	if (root == nullptr)
	{
		root = new node;
		root->data = x;
		return;
	}
	node* a = new node;
	a->data = x;
	node* run = root;
	while (run->next != nullptr) run = run->next;
	run->next = a;
}
void sll::InsertBegin(int x)
{
	node* temp; temp = new node;
	temp->data = x;
	temp->next = root;
	root = temp;
}
bool sll :: InsertTagX(int key, int x) //8
{
	node* temp = root; bool check = false;
	while (temp != nullptr)
	{
		if (temp->data == key)
		{
			if (temp->branch == nullptr)
			{
				node* A = new node;
				A->data = x;
				temp->branch = A;
			}
			else
			{
				check = true;
				node* camp = temp->branch;
				while (camp != nullptr)
				{
					if (camp->next == nullptr) 
					{ 
						node* A = new node; A->data = x;
						camp->next = A; 
						break;
					}
					camp = camp->next;
				}
			}
		}
		temp = temp->next;
	}
	return check;
}

void SingleBranch()
{
	SLL QUANG; string A;
	int n ,a; cout << "The number of nodes: "; cin >> n;
	cin.ignore();
	cout << "Enter the type of insert: (Begin or After) ";  cin >> A;
	cout <<  "Enter your chain of numbers: \n";
	if (A.compare("Begin") == 0)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			QUANG.InsertBegin(a);
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			QUANG.InsertLast(a);
		}
	}
	system("cls");
	cout << "a. Delete A Node\n";
	cout << "b. Insert Before And After\n";
	cout << "c. Delete All X\n";
	cout << "d. Delete Last X\n";
	cout << "e. Edit All X\n";
	char B; cout << "Choose an option (a || b || c || d || e): "; cin >> B;
	system("cls");
	if (B == 'a')
	{
		int x; cout << "Enter a number: "; cin >> x;
		QUANG.DeleteAnode(x);
	}
	else if (B == 'b')
	{
		int x, y; cout << "Enter the functional number: "; cin >> x;
		cout << "Enter the key number: "; cin >> y;
		QUANG.InsertBeforeandAfter(x, y);
	}
	else if (B == 'c')
	{
		int x; cout << "Enter a number: "; cin >> x;
		QUANG.DeleteAllX(x);
	}
	else if (B == 'd')
	{
		int x; cout << "Enter a number: "; cin >> x;
		QUANG.DeleteLastX(x);
	}
	else
	{
		int x, y; cout << "Enter the functional number: "; cin >> x;
		cout << "Enter the key number: "; cin >> y;
		QUANG.EditAllX(x, y);
	}
	QUANG.Display();
}
void MultipleBranch()
{
	sll quang; string A;
	int n, a; cout << "The number of nodes: "; cin >> n;
	cin.ignore();
	cout << "Enter the type of insert: (Begin or After) "; cin >> A;
	cout << "Enter your chain of numbers: \n";
	if (A.compare("Begin") == 0)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			quang.InsertBegin(a);
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			quang.InsertLast(a);
		}
	}
	cout << "There is only Insert Tag X function. Press N then enter to run the function.\n";
	char B; cin >> B;
	if (B == 'N')
	{
		int x, y; cout << "Enter a functional number: "; cin >> x;
		cout << "Enter the key number: "; cin >> y;
		quang.InsertTagX(y, x);
		quang.Display();
	}
	else cout << "Thanks for your visting!!!";
}