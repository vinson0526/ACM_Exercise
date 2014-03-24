#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i != n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int* k = unique(arr, arr + n);
	int* arr2 = arr;
    cout << k - arr2 << endl;
	while(arr2 != k)
    {
        cout << *arr2 << ' ';
        arr2++;
    }
    delete[] arr;
	return 0;
}