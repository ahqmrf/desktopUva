#include<stdio.h> 
#include<stdlib.h> 
int main() 
{
    long long int a,b; 
    while(scanf("%lld %lld", &a, &b)!=EOF)
    {
        a = (a>b)? a-b : b-a;
        printf("%lld\n", a);
    } 
    return 0; 
}

