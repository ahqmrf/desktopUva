#include<stdio.h>
int main ()
{
    int n;
    while(scanf("%d", &n)!=EOF) printf((n%6)? "N\n" : "Y\n");
    return 0;
}
