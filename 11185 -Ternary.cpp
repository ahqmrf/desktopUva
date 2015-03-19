#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main (void)
{
    long long int n;
    while(scanf("%lld", &n) == 1)
    {
        if(n < 0) break;
        else if(n == 0) printf("0");
        else{
            vector<char> ternary;
            while(n > 0){
                int rem = n%3;
                char ch = rem + '0';
                ternary.push_back(ch);
                n /= 3;
            }

            for(int i = ternary.size()-1; i >= 0; --i)
            {
                printf("%c", ternary[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
