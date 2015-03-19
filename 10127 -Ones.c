#include<stdio.h>

int main (void)
{
    long long int num;
    while(scanf("%lld", &num) != EOF)
    {
        if(num == 0)
        {
            printf("0\n");
            continue;
        }
        int mod = 0, nod = 0;
        do
        {
            mod = (mod*10 + 1) % num;
            nod++;
        } while(mod);

        printf("%d\n", nod);
    }
    return 0;
}
