#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<sstream>

using namespace std;
#define MAX 10000002
vector<int> primes;

bool p[MAX];

void sieveMethod()
{
    p[0] = p[1] = true;

    for(int i = 4; i < MAX; i += 2)
    {
        p[i] = true;
    }

    int sq = sqrt(MAX);

    for(int i = 3; i < sq; i+=2)
    {
        if(p[i] == true) continue;
        for(int j = i*i; j < MAX; j += 2*i)
        {
            p[j] = true;
        }
    }

    for(int i = 0; i < MAX; i++)
    {
        if(p[i] == false) primes.push_back(i);
    }

}

int main (void)
{
    sieveMethod();
    string str;
    int s = primes.size(), num;
    vector<int> APrimes;

    for(int i = 0; i < s; i++)
    {
        bool f = true;
        stringstream sss;
        sss << primes[i];
        sss >> str;

        sort(str.begin(), str.end());
        do {
            stringstream ss;
            ss << str;
            ss >> num;

            if(p[num] == true)
            {
                f = false;
                break;
            }
        } while(next_permutation(str.begin(), str.end()));

        if(f == true) APrimes.push_back(primes[i]);
    }

    s = APrimes.size();

    for(int i = 0; i < s; i++)
        cout << APrimes[i] << endl;

    return 0;
}
