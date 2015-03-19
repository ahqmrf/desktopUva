#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main (void)
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        char ch;
        scanf("%c", &ch);
        int a, f, flag = 0, i, j, k;
        scanf("%d%d", &a, &f);

        while(f--)
        {
            if(flag == 1) printf("\n");
            flag = 1;
            for(i = 1; i <= a; i++)
            {
                for(j = 1; j <= i; j++)
                {
                    printf("%d", i);
                }
                printf("\n");
            }


            for(i = a-1; i >= 1; i--)
            {
                for(j = 1; j <= i; j++)
                {
                    printf("%d", i);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
