#include<stdio.h>
long long max = 0, pro;
int arr[20], n, i, j, c = 1;

long long MaxProduct()
{
    max = 0;
    for(i = 0; i < n; i++)
    {
        pro = 1;
        for(j = i; j < n && pro; j++)
        {
            pro *= arr[j];
            if(pro > max) max = pro;
        }
    }

    return max;
}

int main (void)
{
    while(scanf("%d", &n) == 1)
    {
        for(i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        printf("Case #%d: The maximum product is %lld.\n\n", c++, MaxProduct());
    }
    return 0;
}
