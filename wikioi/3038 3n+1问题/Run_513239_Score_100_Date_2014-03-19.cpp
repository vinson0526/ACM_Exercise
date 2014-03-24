#include <iostream>
using namespace std;

int collatz(int n)
{
	int step = 0;
	while(true)
	{
		if(n == 1)
		{
			return step;
		}
		if(n & 1 == 1)
		{
			n = 3 * n + 1;
		}
		else
		{
			n = n / 2;
		}
		step++;
	}
}

int main()
{
	int n = 0;
	cin >> n;
	for(int i = 0; i != n; i++)
	{
		int k = 0;
		cin >> k;
		cout << collatz(k) << endl;
	}
	return 0;
}