#include <iostream>
#include <cmath>
using namespace std;

void isPrime(int n)
{
    if(n == 1)
    {
        cout << "\\n" << endl;
		return;
    }
	for(int i = 2; i <= sqrt(static_cast<double>(n)); i++)
	{
		if(n % i == 0)
		{
			cout << "\\n" << endl;
			return;
		}
	}
	cout << "\\t" << endl;
	return;
}

int main()
{
	int n = 0;
	cin >> n;
	isPrime(n);
}