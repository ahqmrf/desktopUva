#include<iomanip>
#include<string>
#include<cmath>
#include<iostream>
using namespace std;

int main (void)
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        long double N;
        cin >> N;
        cout.precision(0);
        cout.setf(ios::fixed);
        cout << sqrt(N) << endl;
    }
    return 0;
}
