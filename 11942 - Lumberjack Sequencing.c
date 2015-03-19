#include<stdio.h>

int main (void)
{
    int cases;
    scanf("%d", &cases);
    printf("Lumberjacks:\n");
    while(cases--)
    {
        int flag = 0, i, j, temp, a[10];
        for(i = 0; i < 10; i++)
        {
            scanf("%d", &a[i]);
        }

        for(i = 0; i < 9; i++)
        {
            if(a[i] != a[i+1])
            {
                temp = a[i];
                if(a[i] > a[i+1])
                {
                    int res = 0;
                    for(j = i + 1; j < 9; j++)
                    {
                        if(temp < a[j])
                        {
                            res = 1;
                            printf("Unordered\n");
                            break;
                        }
                        temp = a[j];
                    }
                    if(res == 0) printf("Ordered\n");
                }

                else
                {
                    int res = 0;
                    for(j = i + 1; j < 9; j++)
                    {
                        if(temp > a[j])
                        {
                            res = 1;
                            printf("Unordered\n");
                            break;
                        }
                        temp = a[j];
                    }
                    if(res == 0) printf("Ordered\n");
                }
                flag = 1;
                break;
            }
        }

        if(flag == 0) printf("Ordered\n");
    }

    return 0;
}
