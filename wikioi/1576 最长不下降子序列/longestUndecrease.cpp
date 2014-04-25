//题目有误，应为最长增序列
#include <iostream>

using namespace std;

int longest(int *arr, int n)
{
	int *len = new int[n];
	int max = 0;
	for(int i = 0; i != n; i++)
	{
		len[i] = 1;
		for(int j = 0; j != i; j++)
		{
			if(arr[i] > arr[j])
			{
				len[i] = len[i] > (len[j] + 1) ? len[i] : (len[j] + 1);
			}
		}
		max = max > len[i] ? max : len[i];
	}
	return max;
}

int main()
{
	int n = 0;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i != n; i++)
	{
		cin >> arr[i];
	}
	cout << longest(arr, n) << endl;
	return 0;
}
