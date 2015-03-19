#include<cstdio>
#include<algorithm>

using namespace std;

#define MS 1000

int ClosestSum(int myArray[], int n, int sum)
{
    int PCS, CS, PD = -1, D;
    for(int i = 0, j = n-1; i < j; )
    {
        CS = myArray[i] + myArray[j];
        if(CS == sum) return CS;
        D = abs(CS - sum);
        if(CS > sum) j--;
        else i++;
        if(PD == -1 || D < PD)
        {
            PD = D;
            PCS = CS;
        }
    }
    return PCS;
}

int main (void)
{
    int myArray[MS], n, q, s, c = 1;

    while(scanf("%d", &n), n)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &myArray[i]);
        }

        sort(myArray, myArray+n);
        scanf("%d", &q);
        printf("Case %d:\n", c++);
        while(q--)
        {
            scanf("%d", &s);
            printf("Closest sum to %d is %d.\n", s, ClosestSum(myArray, n, s));
        }
    }


}
