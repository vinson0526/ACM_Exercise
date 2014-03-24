#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct line
{
	int start;
	int stop;
};

bool isPre(const line &a, const line &b)
{
	return a.stop < b.stop;
}

int maxLine(vector<line> &vec)
{
	sort(vec.begin(), vec.end(), isPre);
	int count = 0;
	int stopNow = -1000;
	for(int i = 0; i != vec.size(); i++)
	{
		if(vec[i].start >= stopNow)
		{
			count++;
			stopNow = vec[i].stop;
		}
	}
	return count;
}

int main()
{
	int n = 0;
	cin >> n;
	vector<line> vec;
	for(int i = 0; i != n; i++)
	{
		line temp;
		int a, b;
		cin >> a >> b;
		if(a > b)
		{
			temp.start = b;
			temp.stop = a;
		}
		else
		{
			temp.start = a;
			temp.stop = b;
		}
		vec.push_back(temp);
	}
	cout << maxLine(vec) << endl;
	return 0;
}