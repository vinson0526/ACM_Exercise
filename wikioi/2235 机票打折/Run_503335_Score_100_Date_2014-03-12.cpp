#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double price, off;
	cin >> price >> off;
	price = price * off;
	price = round(price / 100) * 10;
	cout << price << endl;
}