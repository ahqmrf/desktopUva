#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
    int n;
        cin >> n;
    while(n-->0) {
        long double mm;
                cin >> mm;
                cout.precision(0);
                cout.setf(ios::fixed);
                cout << sqrt(mm) << endl;
    }

    return 0;
}

