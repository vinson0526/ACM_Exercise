#include <iostream>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

void transfer(string n, int m)
{
	int ten = 0;
	int order = 0;
	for(int i = n.size() - 1; i >= 0; i--)
	{
		char k = n[i];
		int p = 0;
		switch(k)
		{
		case 'A':
			p = 10;
			break;
		case 'B':
			p = 11;
			break;
		case 'C':
			p = 12;
			break;
		case 'D':
			p = 13;
			break;
		case 'E':
			p = 14;
			break;
		case 'F':
			p = 15;
			break;
		default:
			p = k - '0';
			break;
		}
		ten = ten + p * pow(m, order);
		order++;
	}
	
	cout << ten << endl;
}

int main()
{
	int m = 0;
	string n;
	cin >> n >> m;
	transfer(n, m);
}