#include<algorithm>
#include<cmath>
#include<sstream>
#include<string>
#include<cstdio>
#include<iostream>

using namespace std;

int main (void)
{
    string N;
    while(cin >> N)
    {
        string smallest, biggest;
        smallest = N;
        sort(smallest.begin(), smallest.end());
        biggest = smallest;
        reverse(biggest.begin(), biggest.end());
        int k = smallest.length();
        if(smallest[0] == '0')
        {
            for(int i = 1; i<k; i++)
            {
                if(smallest[i]!='0')
                {
                    swap(smallest[0], smallest[i]);
                    break;
                }
            }
        }

        long long s, b;
        s = atoll(smallest.c_str());

        b = atoll(biggest.c_str());

        printf("%lld - %lld = %lld = 9 * %lld\n", b, s, (b-s), (b-s)/9);
    }

    return 0;
}
