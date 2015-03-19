#include<stdio.h>
int digits(int n)
{
    int r = 0;
    while(n) ++r, n /= 10;
    return r;
}

int gcd(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int main (void)
{
    int n, i = 1;


    while(scanf("%d", &n), n)
    {
        int N = n, sum = 0, a, minus = 0;
        while(n--)
        {
            scanf("%d", &a);
            sum += a;
        }
        if(sum < 0)
        {
            minus = 1;
            sum *= -1;
        }
        printf("Case %d:\n", i++);
        if(sum % N == 0)
        {
            if(minus) printf("- ");
            printf("%d\n", sum/N);
        }

        else
        {
            int goshagu = gcd(sum, N);
            sum /= goshagu;
            N /= goshagu;

            if(sum < N)
            {
                if(minus)
                {
                    int length;
                    if(N > 99) length = 3;
                    else if(N > 9) length = 2;
                    else length = 1;

                    if(length == 3) printf("  %3d\n", sum);
                    else if(length == 2) printf("  %2d\n", sum);
                    else printf("  %1d\n", sum);
                    printf("- ");
                    if(length == 3) printf("---\n", sum);
                    else if(length == 2) printf("--\n", sum);
                    else printf("-\n", sum);
                    printf("  %d\n", N);

                }
                else
                {
                    int length;
                    if(N > 99) length = 3;
                    else if(N > 9) length = 2;
                    else length = 1;

                    if(length == 3) printf("%3d\n", sum);
                    else if(length == 2) printf("%2d\n", sum);
                    else printf("%1d\n", sum);

                    if(length == 3) printf("---\n", sum);
                    else if(length == 2) printf("--\n", sum);
                    else printf("-\n", sum);
                    printf("%d\n", N);

                }
            }

            else
            {
                int vagfol = sum/N;
                sum = sum % N;

                int length1 = digits(vagfol);
                int length2 = digits(N);

                if(minus)
                {
                    int c;
                    for(c = 0; c<length1; c++) printf(" ");
                    printf("  ");
                    if(length2 == 3) printf("%3d\n", sum);
                    else if(length2 == 2) printf("%2d\n", sum);
                    else printf("%1d\n", sum);
                    printf("- %d", vagfol);
                    for(c = 0; c < length2; c++) printf("-");
                    printf("\n");
                    for(c = 0; c<length1; c++) printf(" ");
                    printf("  ");
                    printf("%d\n", N);


                }

                else
                {
                    int c;
                    for(c = 0; c<length1; c++) printf(" ");

                    if(length2 == 3) printf("%3d\n", sum);
                    else if(length2 == 2) printf("%2d\n", sum);
                    else printf("%1d\n", sum);
                    printf("%d", vagfol);
                    for(c = 0; c < length2; c++) printf("-");
                    printf("\n");
                    for(c = 0; c<length1; c++) printf(" ");
                    printf("%d\n", N);

                }

            }
        }
    }
}
