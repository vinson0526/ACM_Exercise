#include <iostream>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

void transfer(int n, int m)
{
	stack<char> st;
	for(;n >= m;)
	{
		int k = n % m;
		n = n / m;
		switch(k)
		{
		case 10:
			st.push('A');
			break;
		case 11:
			st.push('B');
			break;
		case 12:
			st.push('C');
			break;
		case 13:
			st.push('D');
			break;
		case 14:
			st.push('E');
			break;
		case 15:
			st.push('F');
			break;
		default:
			st.push(k + '0');
			break;
		}
	}
	switch(n)
	{
	case 10:
		st.push('A');
		break;
	case 11:
		st.push('B');
		break;
	case 12:
		st.push('C');
		break;
	case 13:
		st.push('D');
		break;
	case 14:
		st.push('E');
		break;
	case 15:
		st.push('F');
		break;
	default:
		st.push(n + '0');
		break;
	}
	string mOrder;
	while(!st.empty())
	{
		mOrder = mOrder + st.top();
		st.pop();
	}
	cout << mOrder << endl;
}

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;
	transfer(n, m);
}