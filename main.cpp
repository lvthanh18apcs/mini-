
#include "Header.h"

int main()
{
	int a;
	cout << "1.Linked List with no branch" << endl;
	cout << "2.Linked List with branches" << endl;
	cout << "Enter your option: "; cin >> a; system("cls");
	if (a == 1) SingleBranch();
	else MultipleBranch();
	system("pause");
	return 0;
}


/*
SLL quang;
	std::ifstream in;
	in.open("input.txt");
	if (!in.is_open())
	{
		std::cout << "Couldnt open file";
		return 0;
	}
	in.close();
	quang.Display();

*/

/*
bool k = quang.DeleteAnode(y);
	cout << endl;
	if (k == true) cout << "true\n";
	else cout << "false\n";
*/

/*
int sum = quang.DeleteAllX(y);
	cout << sum << endl;
*/