#include <iostream>
#include <string>
using namespace std;

bool switchBig(string &a, string &b)
{
	if(a.size() < b.size())
	{
		string temp = a;
		a = b;
		b = temp;
		return true;
	}
	else if(a.size() == b.size())
	{
		for(int i = 0; i != a.size(); i++)
		{
			if(a[i] > b[i])
			{
				return false;
			}
			else if(a[i] < b[i])
			{
				string temp = a;
				a = b;
				b = temp;
				return true;
			}
		}
	}
	return false;
}

bool giveOne(string &a, int n)
{
	if(n == -1)
	{
		return true;
	}
	if(a[n] == '9')
	{
		a[n] = '0';
		return giveOne(a, n - 1);
	}
	else
	{
		a[n]++;
	}
	return false;
}

void highSub(string &a, string &b)
{
	bool flag = switchBig(a, b);
	bool tag = false;
	int more = a.size() - b.size();
	for(int i = a.size() - 1; i >= more; i--)
	{
		if(a[i] + b[i - more] - '0' <= '9')
		{
			a[i] = a[i] - '0' + b[i - more];
		}
		else
		{
			tag = giveOne(a, i - 1);
			a[i] = a[i] - '0' - 10 + b[i - more];
		}
	}
	if(tag == true)
	{
		cout << '1';
	}
	cout << a << endl;
}

int main()
{
	string a, b;
	cin >> a >> b;
	highSub(a, b);
	return 0;
}