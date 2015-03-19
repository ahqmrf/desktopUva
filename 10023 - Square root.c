#include<stdio.h>
#include<math.h>

int main (void)
{
    long long int n;
    int cases, f = 0;
    scanf("%d", &cases);
    while(cases-- && scanf("\n%lld", &n) == 1){
        if(f == 1) printf("\n");
        printf("%lld\n", (long long int)sqrt(n));
        f = 1;
    }

    return 0;
}
