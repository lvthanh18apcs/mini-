
#include "Header.h"

int main()
{
	SLL quang;
	int x, n, y; cin >> n >> y;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		quang.InsertLast(x);
	}
	bool k = quang.DeleteAnode(y);
	cout << endl;
	if (k == true) cout << "true\n";
	else cout << "false\n";
	quang.Display();
	system("pause");
	return 0;
}

/*
SLL quang;
	int x, n, y; cin >> n >> y;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		quang.InsertBegin(x);
	}
	bool k = quang.DeleteAnode(y);
	cout << endl;
	if (k == true) cout << "true\n";
	else cout << "false\n";
	quang.Display();
*/