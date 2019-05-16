#include <iostream>

using namespace std;

void sort(int *a, int n,int *b)
{
	for (int i = 1; i < n; ++i)
	{
		int j = i;
		while (a[j] < a[j - 1] && j > 0)
		{
			int temp = a[j];
			int camp = b[j];
			a[j] = a[j - 1];
			b[j] = b[j - 1];
			a[j - 1] = temp;
			b[j - 1] = camp;
			--j;
		}
	}
}
void sort2(int *c, int m)
{
	for (int i = 1; i < m; ++i)
	{
		int j = i;
		while (c[j] < c[j - 1] && j > 0)
		{
			int temp = c[j];
			c[j] = c[j - 1];
			c[j - 1] = temp;
			--j;
		}
	}
}



int main()
{
	int spot, stype, *damage, *strength, *damages;
	cin >> spot;
	damage = new int[spot];
	for (int i = 0; i < spot; ++i) cin >> damage[i];
	cin >> stype;
	strength = new int[stype];
	for (int i = 0; i < stype; ++i) cin >> strength[i];
	delete[] damage;
	delete[] strength;
	system("pause");
	return 0;
}