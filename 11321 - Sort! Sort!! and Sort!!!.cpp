#include<bits/stdc++.h>

using namespace std;
int modulo;
bool cmp(int a, int b)
{
    if(a%modulo != b%modulo)
       return a%modulo < b%modulo;
    else
    {
        if(abs(a)%2 == 0 && abs(b)%2 == 0)
          return a<b;
        else if(abs(a)%2 != 0 && abs(b)%2 != 0)
                return a>b;
        else if(abs(a)%2 != 0)
                return true;
        else
            return false;
    }
}
int main()
{
    int N;
    int a[10001];
    while(scanf("%d%d", &N, &modulo)==2)
    {
        if(N==0 && modulo==0)
        {
            printf("0 0\n");
            break;
        }
        for(int i=0; i<N; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a+N, cmp);
        printf("%d %d\n", N, modulo);
        for(int i=0; i<N; i++)
        {
            printf("%d\n", a[i]);
        }
    }
    return 0;
}
