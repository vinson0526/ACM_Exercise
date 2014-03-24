#include <iostream>
using namespace std;

int strange(int n)
{
	if(n >= 0)
	{
		return 5;
	}
	else
	{
		return strange(n + 1) + strange(n + 2) + 1;
	}
}

int main()
{
	int n = 0;
	cin >> n;
	cout << strange(n) << endl;
	return 0;
}