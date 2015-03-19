#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main (void)
{
    int n;


    while(scanf("%d", &n) == 1 && n){
        bool space = true;
        int c[n+1];
        memset(c, 0, sizeof(c));

        for(int i = 0; i < n; ++i)
        {
            int a;

            scanf("%d", &a);

            c[a]++;
        }

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < c[i]; ++j)
            {
                if(space == false) printf(" ");
                printf("%d", i);
                space = false;
            }
        }
        printf("\n");


    }
    return 0;
}
