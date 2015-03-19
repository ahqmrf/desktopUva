#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    long long int x, n, i, srt;
    int cases;
    scanf("%d", &cases);
    for(int c=1; c<=cases; c++)
    {
        scanf("%lld", &n);
        srt = sqrt(n);
        printf("Case %d:",c);
        for(int j=srt; j>0; --j)
        {
            x = n-j*j;
            if(x%j==0 && x>=j) printf(" %lld", x);
        }
        printf("\n");
    }
    return 0;
}
