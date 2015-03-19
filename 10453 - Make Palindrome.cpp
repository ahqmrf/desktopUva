#include<cstring>
#include<bits/stdc++.h>
#define maxN 1100

using namespace std;

char text[maxN], pattern[maxN];
int f[maxN], length, index;

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
            index = j;
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
        length = strlen(text);
        for(int i = 0, j = length - 1; i < length; i++, j--)
            pattern[i] = text[j];
        index = 0;
        kmpSearch();
        printf("%d %s", length - index, text);
        for(int i = index; i < length; i++)
            printf("%c", pattern[i]);
        puts("");
    }
    return 0;
}

