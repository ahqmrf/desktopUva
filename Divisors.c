#include<stdio.h>
#include<math.h>

#define MAX 100010

int main (void)
{
    long long i, j, a, b, k, d, squareRoot, cases, NOfDivisors[MAX], SumOfDivisors[MAX], g, h;
    NOfDivisors[1] = 1;
    SumOfDivisors[1] = 1;


    for(i = 2; i < MAX; i++)
    {
        NOfDivisors[i] = 2;
        SumOfDivisors[i] = i + 1;
        squareRoot = sqrt(i);

        for(j = 2; j <= squareRoot; j++)
        {
            if(i % j == 0)
            {
                NOfDivisors[i] += 2;
                SumOfDivisors[i] += (j + i/j);
            }
        }

        if(squareRoot * squareRoot == i)
        {
            NOfDivisors[i]--;
            SumOfDivisors[i] -= squareRoot;
        }
    }

    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%lld %lld %lld", &a, &b, &k);
        d = a/k;
        if(k*d != a) a = (d+1) * k;
        g = 0;
        h = 0;

        while(a <= b)
        {
            g += NOfDivisors[a];
            h += SumOfDivisors[a];
            a += k;
        }

        printf("%lld %lld\n", g, h);
    }


    return 0;
}
