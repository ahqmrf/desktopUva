#include<stdio.h>
#include<string.h>

int main ()
{
    char str[1000001];
    int sl, max, i;
    while(gets(str) && strcmp(str, "."))
    {
        max = 1;
        sl = strlen(str);
        for(i=1; i<sl; i++)
            while(str[i]!=str[i%max])
                max++;

        if(sl%max) printf("1\n");
        else printf("%d\n", sl/max);
    }
    return 0;
}
