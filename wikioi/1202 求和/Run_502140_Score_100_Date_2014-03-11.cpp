#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int sum = 0;
    for(int i = 0; i != n; i++)
    {
        int temp = 0;
        cin >> temp;
        sum += temp;
    }
    cout << sum << endl;
    return 0;
}