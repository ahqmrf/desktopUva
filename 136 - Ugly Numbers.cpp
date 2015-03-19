#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

bool primeChecker (unsigned long long int num)
{
    bool flag = true;
    for(unsigned long long int i = 2; i < num/2; ++i)
    {
        if(num%i == 0)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

int main ()
{
    vector<unsigned long long int> primes;
    unsigned long long int limit = pow(2, 32);
    for(unsigned long long int i = 2; i < limit; ++i)
    {
        bool flag = primeChecker(i);
        if(flag) primes.push_back(i);
    }

    for(int i = 0; i < 25; ++i)
    {
        cout << primes[i] << endl;
    }

    return 0;
}
