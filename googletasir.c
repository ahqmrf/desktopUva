#include <stdio.h>
#include <string.h>

int main()
{
    int testCase,count=0;
    scanf("%d",&testCase);

    while(testCase--)
    {
        count++;

        char webSite[10][500];
        int siteCount[10],i;

        for(i=0;i<10;i++)
        {
            gets(webSite[i]);
        }

        for(i=0;i<10;i++)
        {
            puts(webSite[i]);
        }

    }
    return 0;
}

