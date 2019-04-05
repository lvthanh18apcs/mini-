#include <iostream>
#include <vector>
#include <math.h>
#include <string>

using namespace std;

/*int migratoryBirds(vector<int> arr) {
	vector <int> count;
	int n = arr.size();
	vector <int> kind;
	kind.push_back(arr[0]);
	count.push_back(1);
	for (int i = 1; i < n; ++i)
	{
		int temp = arr[i];
		bool in = false;
		for (int j = 0; j <= kind.size(); ++j)
		{
			if (temp == kind[j])
			{
				in = true;
				++count[j];
				break;
			}
		}
		if (in == false)
		{
			kind.push_back(temp);
			count.push_back(1);
		}
	}
	int max = 0, wmax = kind[0];
	n = kind.size();
	for (int i = 0; i < n; ++i)
		if (count[i] > max)
		{
			max = count[i];
			wmax = kind[i];
		}
	return wmax;
}*/


int main()
{
	
	system("pause");
	return 0;
}

void ex01()
{
	int a[1000];
	int temp;
	cin >> temp;
	int i = -1;
	while (temp != 0)
	{
		++i;
		a[i] = temp;
		cin >> temp;
	}
	for (int j = 0; j <= i / 2; ++j)
	{
		int temp = a[j];
		a[j] = a[i - j];
		a[i - j] = temp;
	}
	for (int j = 0; j <= i; ++j)
		cout << a[j] << " ";
}

void laptopv2()
{
	char a[1000];
	cin.get(a, 1000, '\n');
	cin.ignore();
	int s = strlen(a);
	int j;
	for (int i = s - 1; i > -1; --i)
	{
		if (a[i] != ' ')
		{
			j = i - 1;
			while (a[j] != ' ' && j != -1)
				--j;
			for (int k = j + 1; k <= i; ++k)
				cout << a[k];
			cout << ' ';
			i = j;
		}
	}
}