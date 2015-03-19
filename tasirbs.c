#include <stdio.h>

int main()
{

    for(;;)
    {
        long long int n,r,answer;
        double ans=1;
        scanf("%lld %lld",&n,&r);

        if (r>n)
        continue;

        if(n==0 && r==0)
        break;

        long long int i,j=r;
        for(i=0;i<j;i++)
        {
            ans=ans*n/r;

            n--;
            r--;
        }

        answer=ans;

        printf("%lld\n",answer);

    }
    return 0;
}
