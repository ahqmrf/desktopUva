#include<bits/stdc++.h>

using namespace std;
int a[1000001], b[1000001];

int main()
{
    int N, M;

    while(scanf("%d%d", &N, &M), M||N)
    {
        int noc = 0;
        for(int k=0; k<N; k++)
        {
            scanf("%d", &a[k]);
        }
        for(int k=0; k<M; k++)
        {
            scanf("%d", &b[k]);
        }

        int i=0, j=0;
        while(i<N && j<M)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
                noc++;
            }
            else if(a[i] > b[j]) j++;
            else i++;
        }
        printf("%d\n", noc);
    }
    return 0;
}
