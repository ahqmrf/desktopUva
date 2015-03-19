#include<string.h>
#include<stdio.h>
#define maxN 100010

char text[maxN], pattern[maxN];
int f[maxN], length, startOfExtra;

void computeFailureFunction()
{
    int i = 1, j = 0;
    f[0] = 0;

    while(i < length)
    {
        if(pattern[i] == pattern[j])
        {
            j++;
            f[i] = j;
            i++;
        }
        else if(j > 0)
            j = f[j-1];
        else
        {
            f[i] = 0;
            i++;
        }
    }
}

void kmpSearch()
{
    computeFailureFunction();
    int i = 0, j = 0;
    while(i < length)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
            startOfExtra = j;
        }
        else if(j > 0)
            j = f[j-1];
        else
            i++;
    }
}

int main()
{
    while(gets(text))
    {
        memset(f, 0, sizeof f);
        int i, j;
        length = strlen(text);
        for(i = 0, j = length - 1; i < length; i++, j--)
            pattern[i] = text[j];
        startOfExtra = 0;
        kmpSearch();
        printf("%s", text);
        for(i = startOfExtra; i < length; i++)
            printf("%c", pattern[i]);
        printf("\n");
    }
    return 0;
}

