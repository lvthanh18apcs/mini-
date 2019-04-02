

int main()
{
	int sum = 0;
	while (1 != 0)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		else
		{
			if (n == 2) sum += n;
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
				sum += n;
			}
		}
	}
	cout << "Sum of prime number(s) is: " << sum;
	system("pause");
	return 0;
}