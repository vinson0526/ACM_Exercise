#include <iostream>
using namespace std;

void mean(int *arr, int n)
{
	int sum = 0;
	for(int i = 0; i != n; i++)
	{
		sum += arr[i];
	}
	int average = sum / n;
	int local_sum = 0;
	int local_count = 0;
	int count = 0;
	for(int i = 0; i != n; i++)
	{
		local_sum = local_sum + arr[i];
		local_count++;
		if(local_sum >= average * local_count)
		{
			count = count + local_count - 1;
			if(local_sum > average * local_count)
			{
				arr[i + 1] = arr[i + 1] + local_sum - average * local_count;
				count++;
			}
			local_count = 0;
			local_sum = 0;
		}
	}
	cout << count << endl;
}

main()
{
    int n = 0;
    cin >> n;
	int *arr = new int[n];
	for(int i = 0; i != n; i++)
	{
		cin >> arr[i];
	}
	mean(arr, n);
}