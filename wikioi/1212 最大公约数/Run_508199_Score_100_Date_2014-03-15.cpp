#include <iostream>

using namespace std;

int gcd(int n, int m)
{
	return m == 0 ? n : gcd (m, n % m);
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	cout << gcd(n, m) << endl;
	return 0;
}