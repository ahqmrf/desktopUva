#include<string.h>
#include<stdio.h>

int main (void)
{
    char slogans[200][2][200];
    char input[200];
    int nos, query, i;
    scanf("%d\n", &nos);
    for(i=0; i<nos; i++)
    {
        gets(slogans[i][0]);
        gets(slogans[i][1]);
    }
    scanf("%d\n", &query);
    while(query--)
    {
        gets(input);
        for(i=0; i<nos; i++)
        {
            if(!strcmp(input, slogans[i][0]))
            {
                printf("%s\n", slogans[i][1]);
                break;
            }
        }
    }
    return 0;
}
