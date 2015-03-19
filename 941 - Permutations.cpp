#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int main (void)
{
    long long Factorial[20];
    Factorial[0] = Factorial[1] = 1;
    for(int i=2; i<20; ++i)
    {
        Factorial[i] = Factorial[i-1]*i;
    }

    //printf("%lld\n", Factorial[19]*20);

    char str[30];
    int cases;
    long long N;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%s", str);
        scanf("%lld", &N);
        int length = strlen(str);
        sort(str, str+length);
        vector<char> op(str, str+length), nthComb;

        for(int i=length-1; i; i--)
        {
            int j = N/Factorial[i];
            nthComb.push_back(op[j]);
            op.erase(op.begin()+j);
            N %= Factorial[i];
        }

        nthComb.push_back(op[0]);
        nthComb.push_back('\0');
        printf("%s\n", &nthComb[0]);
    }
    return 0;
}
