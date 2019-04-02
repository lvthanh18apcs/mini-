void IsPrime()
{
	cout << "Input n: "; 
	int n; cin >> n;
	if (n == 2) cout << "2 is prime number" << endl;
	else if (n % 2 == 0 || n < 2) cout << n << " is not a prime number" << endl;
	else
	{
		for (int i = 3; i <= sqrt(n); ++i)
		{
			if (n % i == 0)
			{
				cout << n << " is not prime number" << endl;
				return;
			}
		}
		cout << n << " IS A PRIME NUMBER" << endl;
	}
}