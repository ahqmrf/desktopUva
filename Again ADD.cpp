#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<sstream>

using namespace std;

int main (void)
{
    int n;
    while(cin >> n, n)
    {
        char ch;
        string str;
        long long num;
        long long sum = 0;
        while(n--)
        {
            cin >> ch;
            str += ch;
        }

        sort(str.begin(), str.end());
        do {
            stringstream ss;
            ss << str;
            ss >> num;
            sum += num;
        } while(next_permutation(str.begin(), str.end()));
        printf("%lld\n", sum);
    }
    return 0;
}
