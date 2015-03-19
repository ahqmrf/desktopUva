#include<stdio.h>

int main()
{
    long long int fibonacci[128], n, i;
    fibonacci[0] = fibonacci[1] = 1;
    for(i = 2; i<81; i++) fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];

    while(scanf("%lld",&n), n) printf("%lld\n", fibonacci[n]);

    return 0;

}
