void Ex1_FullReverse()
{
	int n;
	char str[1000];
	cin.get(str, 1000, '\n');
	cin.ignore();
	n = strlen(str);
	for (int i = n - 1; i >= 0; --i) {
		cout << str[i];
	}
	cout << endl;
}
// Accepted

void Ex2_PartialReverse()
{
	int n;
	char str[1000];
	cin.get(str, 1000, '\n');
	cin.ignore();
	n = strlen(str);
	int m = n - 1;
	for (int i = m; i >= 0; --i)
	{
		if (str[i] == ' ')
		{
			for (int j = i; j <= m; ++j)
			{
				cout << str[j];
			}
			m = i - 1;
		}
	}
	cout << " " << str[0] << endl;
} 
// miss one case. when i reaches 0, means the first char of the string and it founds there is no ' ' so it doesnt complete its jobto find the word
// try another way of thinking, run backward, but instead of seeking for ' ', seek for the first letter of the word, like if the word is 'word' we
// seek for the letter 's' because we run backward

void Ex3_Even()
{
	int a = 0, b = 0, k = 2;
	int str[1000];
	for (int i = 0; i < 1000; ++i) {
		cin >> str[i];
		if (str[i] == 0) {
			for (int j = 0; j < i; ++j)
			{
				if (str[j] % 2 == 0) a = a + str[j];
			}
			break;
		}
	}
	cout << a << endl;
}
//Accepted

void Ex4_Prime()
{
	int sum = 0;
	while (1 != 0)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		else
		{
			if (n < 2 || (n % 2 == 0 && n != 2)) sum -= n;
			else
			{
				for (int i = 3; i <= sqrt(n); ++i)
				{
					if (n % i == 0)
					{
						sum -= n;
						break;
					}
				}
			}
			sum += n;
		}
	}
	cout << "Sum of prime number(s) is: " << sum << endl;
}
//Accepted

void Ex5_DuplicateWithoutErasing()
{
	int str[1000];
	int n = 0, temp, camp;
	while (1 != 0)
	{
		cin >> str[n];
		if (str[n] == 0) break;
		++n;
	}
	for (int i = 1; i < n; ++i)
	{
		while (str[i] < str[i - 1] && i > 0)
		{
			int a = str[i];
			str[i] = str[i - 1];
			str[i - 1] = a;
			i -= 1;
		}
	}
	int i = 0;
	int x = n;
	while (i < x)
	{
		int j = i + 1;
		if (str[i] == str[j])
		{
			while (j < x)
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
				if (j == x - 1) x = x - 1;
				++j;
			}
			if (str[i] == str[i + 1]) continue;
			else ++i;
		}
		else ++i;
	}
	for (int k = 0; k < x; ++k)
	{
		cout << str[k] << endl;
	}
}
//Accepted, well done but a bit long, is there any shorter way?

void Ex6_DuplicateWithErasing()
{
	int str[1000];
	int n = 0, temp, camp;
	while (1 != 0)
	{
		cin >> str[n];
		if (str[n] == 0) break;
		++n;
	}
	for (int i = 1; i < n; ++i)
	{
		while (str[i] < str[i - 1] && i > 0)
		{
			int a = str[i];
			str[i] = str[i - 1];
			str[i - 1] = a;
			i -= 1;
		}
	}
	int i = 0;
	int x = n;
	while (i < x)
	{
		int j = i + 1;
		if (str[i] == str[j])
		{
			while (j < x)
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
				if (j == x - 1) x = x - 1;
				++j;
			}
			if (str[i] == str[i + 1]) continue;
			int k = 0;
			while (k < x)
			{
				camp = str[k];
				str[k] = str[k + 1];
				str[k + 1] = camp;
				if (k == x - 1) x = x - 1;
				++k;
			}
			if (str[i] == str[i + 1]) continue;
			else ++i;
		}

		else ++i;
	}
	for (int k = 0; k < x; ++k)
	{
		cout << str[k] << endl;
	}
}
//Accepted, again is there any shorter way?

void Ex7_Permutation()
{
	int str[10];
	for (int i = 1; i <= 3; ++i)
	{
		cin >> str[i];
		if (i == 3)
		{
			if (str[1] == str[2] && str[2] == str[3]) cout << str[1] << str[2] << str[3] << endl;
			else if ((str[1] == str[2] && str[2] != str[3]) || (str[1] != str[2] && str[2] == str[3]) || (str[1] == str[3] && str[3] != str[2]))
			{
				for (int j = 1; j <= i; ++j)
				{
					int a = j + 1;
					int b = j + 2;
					if (a > 3)
					{
						a = a - i;
						b = b - i;
						cout << str[j] << str[a] << str[b] << endl;
					}
					else if (b > 3)
					{
						b = b - i;
						cout << str[j] << str[a] << str[b] << endl;
					}
					else cout << str[j] << str[a] << str[b] << endl;

				}
			}
			else
			{
				if (1 != 0)
				{

					for (int j = 1; j <= i; ++j)
					{
						int a = j + 1;
						int b = j + 2;
						if (a > 3)
						{
							a = a - i;
							b = b - i;
							cout << str[j] << str[a] << str[b] << endl;
						}
						else if (b > 3)
						{
							b = b - i;
							cout << str[j] << str[a] << str[b] << endl;
						}
						else cout << str[j] << str[a] << str[b] << endl;
					}
				}
				if (2 != 1)
				{
					for (int j = 1; j <= i; ++j)
					{
						int a = j + 2;
						int b = j + 1;
						if (b > 3)
						{
							a = a - i;
							b = b - i;
							cout << str[j] << str[a] << str[b] << endl;
						}
						else if (a > 3)
						{
							a = a - i;
							cout << str[j] << str[a] << str[b] << endl;
						}
						else cout << str[j] << str[a] << str[b] << endl;
					}
				}
			}
		}
	}
}
// User only input one number, is 3 print out the permutation from 1 to 3
// wrong input format

void Ex8_ArrayInsert()
{
	int A[1000];
	int a, x, position;
	cin >> x;
	cin >> position;
	for (int i = 0; i < 1000; ++i)
	{
		cin >> A[i];
		if (A[i] == 0) break;
		a = i + 1;
	}
	if (position < a) A[position] = x;
	for (int j = 0; j < a; ++j) cout << A[j] << endl;
}
// wrong answer, insert a number not replace X to position k :)

void Ex9_RemoveNumberWithPosition()
{
	int position, a, temp;
	cin >> position;
	int A[10000];
	for (int i = 0; i < 10000; ++i)
	{
		cin >> A[i];
		if (A[i] == 0) break;
		a = i;
	}
	while (position < a)
	{
		temp = A[position];
		A[position] = A[position + 1];
		A[position + 1] = temp;
		++position;
	}
	for (int j = 0; j < a; ++j)
	{
		cout << A[j] << endl;
	}
}
// wrong answer in input: 10 1 2 3 0, check it again 

void Ex10_RemoveNumber()
{

	int X, a, temp, z;
	int A[10000];
	cin >> X;
	for (int i = 0; i < 10000; ++i)
	{
		cin >> A[i];
		if (A[i] == 0) break;
		a = i;
	}
	int j = 0;
	while (j <= a) {
		if (A[j] == X)
		{
			while (j <= a)
			{
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				++j;
				z = 0;
				--a;
			}
		}
		else if (j == a && A[j] != X)
		{
			z = 5;
			++j;
		}
		else ++j;
	}
	if (z == 5) cout << "There is no X" << endl;
	else
	{
		for (int i = 0; i <= a; ++i)
			cout << A[i] << endl;
	}
}
// wrong answer in input: 1 1 2 3 4 5 0
//						  2 1 2 3 4 5 0
//						  1 1 1 1 1 1 1 1 1 1 1 1 0

void Ex11_MergeArray()
{
	int str[1000];
	int arr[1000];
	int sum[10000];
	int m, n;
	int k = 0;
	for (int i = 0; i < 1000; ++i)
	{

		cin >> str[i];
		if (str[i] == 0)
		{
			m = i;
			break;

		}
		else
		{
			while (k == i)
			{
				sum[k] = str[i];
				++k;
			}
		}

	}
	int l = m;
	for (int j = 0; j < 1000; ++j)
	{

		cin >> arr[j];
		if (arr[j] == 0)
		{
			n = j;
			break;
		}
		else
		{
			while (l == j + m)
			{
				sum[l] = arr[j];
				++l;
			}
		}
	}
	for (int x = 1; x < (m + n); ++x)
	{
		while (sum[x] < sum[x - 1] && x > 0)
		{
			int a = sum[x];
			sum[x] = sum[x - 1];
			sum[x - 1] = a;
			x -= 1;
		}
	}
	for (int x = 0; x < (m + n); ++x)
	{
		cout << sum[x] << " ";
	}
}
// Accepted 
// although the way to do this problem is wrong
// what if i only give you 2 array of integers, what if i tell you you only have one scan for each array


void Ex12_FibonacciArray()
{
	int x;
	int arr[1000];
	arr[0] = 0;
	arr[1] = 1;
	cin >> x;
	if (x > 1)
	{
		for (int i = 1; i < 1000; ++i)
		{
			arr[i + 1] = arr[i] + arr[i - 1];
			if (x == i + 1)
			//{
				cout << arr[i + 1] << endl;
			//	break;
			//}
		}
	}
	else if (x == 0) cout << arr[0] << endl;
	else cout << arr[1] << endl;
}
// there is an error because it exceeds 1000 numbers, check it again and when you reach the number 'n' print out result and break
// check the note



------ 6/12 accepted ------