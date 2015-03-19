#include<stdio.h>
#include<string.h>

int main (void)
{
    char number[200], i, size, mod17;
    while(gets(number))
    {
        if(!strcmp(number, "0")) break;
        mod17 = 0;

        size = strlen(number);

        for(i = 0; i < size; i++)
        {
            mod17 = (mod17*10 + number[i] - '0') % 17;
        }

        if(mod17) printf("0\n");
        else printf("1\n");
    }
    return 0;
}
