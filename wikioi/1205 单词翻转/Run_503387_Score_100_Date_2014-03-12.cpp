#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<string> st;
	string in;
	while(cin >> in)
	{
		st.push(in);
	}
	while(!st.empty())
	{
		if(st.size() == 1)
		{
			cout << st.top() << endl;
			st.pop();
		}
		else
		{
			cout << st.top() << ' ';
			st.pop();
		}
	}
	return 0;
}