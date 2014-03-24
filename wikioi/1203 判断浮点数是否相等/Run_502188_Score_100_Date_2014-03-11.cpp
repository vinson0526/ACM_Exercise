#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a = 0.0, b = 0.0;
    cin >> a >> b;
    if(abs(a - b) <= 0.00000001)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}