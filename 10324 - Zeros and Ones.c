#include<stdio.h>
#include<string.h>

#define MAX 1000000

char str [MAX];

int min(int a , int b)
{
	return (a<b)? a : b ;
}

int max(int a , int b)
{
	return (a>b)? a : b ;
}


int main (void)
{
    int case_no = 0, q, i, a, b, flag;
    while(gets(str))
    {
        scanf("%d", &q);

        printf("Case %d:\n", ++case_no);
        for(i = 0; i < q; i++)
        {
            scanf("%d%d", &a, &b);
            flag = 1;
            if(a == b) flag = 1;
            else
            {
                int x = min(a, b), y = max(a, b), j;

                for(j = x; j < y; j++)
                {
                    if(str[j] != str[j+1])
                    {
                        flag = 0;
                        break;
                    }
                }


            }

            (flag)? printf("Yes\n") : printf("No\n");
            getchar();

        }
    }
    return 0;
}
