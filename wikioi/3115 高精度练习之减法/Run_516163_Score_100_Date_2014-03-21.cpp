#include <iostream>
#include <string>
#include <cstdlib>
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

void borrowOne(string &a, int n)
{
	if(a[n] == '0')
	{
		a[n] = '9';
		borrowOne(a, n - 1);
	}
	else
	{
		a[n]--;
	}
}

void highSub(string &a, string &b)
{
	bool flag = switchBig(a, b);
	int more = a.size() - b.size();
	for(int i = a.size() - 1; i >= more; i--)
	{
		if(a[i] >= b[i - more])
		{
			a[i] = '0' + a[i] - b[i - more];
		}
		else
		{
			borrowOne(a, i - 1);
			a[i] = '0' + 10 - b[i - more] + a[i];
		}
	}
	if(flag == true)
	{
		cout << '-';
	}
	bool tag = false;
	for(int i = 0; i != a.size(); i++)
	{
		if(tag == false && a[i] == '0')
		{
			continue;
		}
		if(a[i] != '0')
		{
			tag = true;
		}
		cout << a[i];
	}
	cout << endl;
}

int main()
{
	string a, b;
	cin >> a >> b;
	highSub(a, b);
	return 0;
}