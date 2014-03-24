#include <iostream>
using namespace std;

void transfer(int n, int &count)
{
	for(int i = 1; i <= n / 2; i++)
	{
		count++;
		transfer(i, count);
	}
}

int main()
{
	int n = 0;
	cin >> n;
	int count = 1;
	transfer(n, count);
	cout << count << endl;
}