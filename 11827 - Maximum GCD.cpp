#include<sstream>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

long long int gcd(long long int a, long long int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int main (void)
{
    int test;
    cin >> test;
    string input;
    getline(cin, input);
    int num;
    while(test--)
    {
        vector<int> a;

        getline(cin, input);
        istringstream iss(input);
        while(iss >> num)
        {
            a.push_back(num);
        }

        int n = a.size();

        int g, maxG = 1;

        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                g = gcd(a[i], a[j]);
                if(g >= maxG)
                {
                    maxG = g;
                }
            }
        }

        cout << maxG << endl;

    }
    return 0;
}
