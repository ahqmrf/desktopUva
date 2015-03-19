#include<stdio.h>
#include<string.h>

int main (void)
{
    char in[10000];
    while(gets(in))
    {
        printf("%s\n", in);
    }
    return 0;
}
