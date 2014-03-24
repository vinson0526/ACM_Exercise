#include <iostream>
#include <vector>
#include <string>
using namespace std;

void giveSome(vector<int> &c, int k, int n)
{
	int temp = c[k] + n;
	if(temp >= 9)
	{
		c[k] = temp;
	}
	else
	{
		c[k] = temp % 10;
		giveSome(c, k - 1, temp / 10);
	}
}

void onceMulti(string &a, int b, vector<int> &c,int k)
{
	for(int j = a.size() - 1; j >= 0; j--)
	{
		int temp = (a[j] - '0') * b + c[c.size() - k - (a.size() - 1 - j)];
		c[c.size() - k - (a.size() - 1 - j)] = temp % 10;
		giveSome(c, c.size() - k - (a.size() - 1 - j) - 1, temp / 10);
	}
}

void bigMulti(string &a, string &b, vector<int> &c)
{
	for(int i = b.size() - 1; i >= 0; i--)
	{
		onceMulti(a, b[i] - '0', c, b.size() - i);
	}
}

int main()
{
	string a, b;
	cin >> a >> b;
	vector<int> c;
	for(int i = 0; i != 1000; i++)
	{
		c.push_back(0);
	}
	bigMulti(a, b, c);
	bool tag = false;
	for(int i = 0; i != 1000; i++)
	{
		if(tag == false && c[i] == 0)
		{
			continue;
		}
		if(tag == false && c[i] != 0)
		{
			tag = true;
		}
		cout << c[i];
	}
	cout << endl;
}