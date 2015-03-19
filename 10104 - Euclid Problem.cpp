#include<bits/stdc++.h>
#define int64 long long int

using namespace std;

int solve(int a, int b, int &x, int &y)
{
    if(a < b) return solve(b, a, y, x);
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int p, q;
    int s = solve(b, a%b, p, q);
    x = q;
    y = (p-a/b*q);
    return s;
}

int main()
{
    int a, b, x, y;
    while(scanf("%d%d", &a, &b) == 2)
    {
        int gcd = solve(a, b, x, y);
        printf("%d %d %d\n", x, y, gcd);
    }
    return 0;
}
