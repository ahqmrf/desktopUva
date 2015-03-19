#include<stdio.h>
int main (void)
{

    int n = 341, i;
    for(i = 2; i < 341; i++)
    {
        if(n % i == 0) printf("%d\n", i);
    }
}
