#include<stdio.h>

int main()
{
    int s[13], n, i, j, k, l, m, p, b = 0;
    while(scanf("%d", &n), n)
    {
        for(i = 0; i < n; i++)
            scanf("%d", &s[i]);
        if(b) printf("\n");
        b = 1;
        for(i = 0; i < n; i++)
            for(j = i+1; j < n; j++)
                for(k = j+1; k < n; k++)
                    for(l = k+1; l < n; l++)
                        for(m = l+1; m < n; m++)
                            for(p = m+1; p < n; p++)
                            printf("%d %d %d %d %d %d\n", s[i], s[j], s[k], s[l], s[m], s[p]);
    }
    return 0;
}
