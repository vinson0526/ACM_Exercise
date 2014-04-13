#include <iostream>

using namespace std;

typedef struct
{
	unsigned int high;
	unsigned int count;
}inter;

unsigned int missile(unsigned int *high, int n)
{
	int *most = new int[n];
	int max = 1;
	for(int i = n - 1; i != -1; i--)
	{
		most[i] = 1;
		for(int j = i; j != n; j++)
		{
			if(high[i] > high[j])
			{
				most[i] = most[i] > most[j] + 1 ? most[i] : most[j] + 1;
			}
		}
		max = max > most[i] ? max : most[i];
	}
	return max;
}

int how_much(unsigned int* high, int n)
{
	int count = 0;
	int num = 0;
	int *has_killed = new int[n];
	for(int i = 0; i != n; i++)
	{
		has_killed[i] = 0;
	}
	while(count != n)
	{
		int now = 0;
		for(int i = 0; i != n; i++)
		{
			
			if(has_killed[i] == 0 && (now == 0 || high[i] <= now))
			{
				now = high[i];
				has_killed[i] = 1;
				count++;
			}
		}
		num++;
	}
	return num;
}

int main()
{
	int n = 0;
	unsigned int temp = 0;;
	unsigned int* high_temp = new unsigned int[20];
	while(cin >> temp)
	{
		high_temp[n] = temp;
		n++;
	}
	unsigned int* high = new unsigned int[n];
	for(int i = 0; i != n; i++)
	{
		high[i] = high_temp[i];
	}
	delete[] high_temp;
	cout << missile(high, n) << endl;
	cout << how_much(high, n) << endl;
}
