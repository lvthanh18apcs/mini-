#include <iostream>
using namespace std;
int main() {
	int a = 0, b = 0, k=2 ;
	int str[1000];
	for (int i = 0; i < 1000; ++i) {
		cin >> str[i];
		if ( str[i] == 0) { 
			for (int j = 0; j < i; ++j) {
				/*if (str[j] % 2 == 0) {
					a = a + str[j];
				} */
				while ( k >= 2 && k < sqrt(str[j]) )
				{
					if (str[j] % k == 0) {
						++j;

						}
					}
					b = b + str[j];
					++k;
								
				//break;
			}
			break;
		} 		
	}
	/* cout << a << endl;   even number */
	cout << b << endl; // prime number

	system("pause");
	return 0;
}   
