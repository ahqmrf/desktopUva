#include<iostream>
#include<iomanip>

using namespace std;

long double factorial(long double num)
{
    long double f = 1;
    for(long double i = 2; i <= num; i++)
    {
        f *= i;
    }

    return f;
}

int main (void)
{
    long double N, M;
    while(cin >> N >> M && N!=0 && M != 0)
    {

        long double C = factorial(N) / (factorial(N-M)* factorial(M));
        cout << N << " things taken " << M << " at a time is " << fixed << setprecision(0) << C << " exactly." << endl;
    }
    return 0;
}
