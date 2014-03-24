#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int min = 0, max = 0;
    cin >> min;
    max = min;
    for(int i = 1; i != n; i++)
    {
        int temp = 0;
        cin >> temp;
        if(temp > max)
            max = temp;
        if(temp < min)
            min = temp;
    }
    cout << min << ' ' << max << endl;
    return 0;
}