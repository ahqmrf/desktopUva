#include<algorithm>
#include<cstdio>
using namespace std;

int main (void)
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int N;
        scanf("%d", &N);
        int *street = new int[N];
        for(int i=0; i<N; i++)
        {
            scanf("%d", &street[i]);
        }
        sort(street, street+N);
        int dSum = 0;
        for(int i=1; i<N; i++)
        {
            dSum += (street[i]-street[i-1]);
        }

        printf("%d\n", dSum*2);
    }
    return 0;
}
