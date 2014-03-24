#include <iostream>

using namespace std;

void cantor(int n)
{
	int i = 1;
	for(;;i++)
	{
		int N = (1 + i) * i / 2;
		if(N >= n)
		{
			break;
		}
	}
	if(i == 1)
	{
		cout << "1/1" << endl;
	}
	else
	{
		i--;
		int N = (1 + i) * i / 2;
		int k = n - N;
		if((i + 1) % 2 == 0)
		{
			cout << k << '/' << i + 2 - k << endl;
		}
		else
		{
			cout << i + 2 - k << '/' << k << endl;
		}
	}
}

int main()
{
	int n = 0;
	cin >> n;
	cantor(n);
	return 0;
}