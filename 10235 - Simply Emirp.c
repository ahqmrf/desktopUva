#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX 1000000

int p[MAX];

void sieveMethod()
{
    memset(p, 0, sizeof(p));
    p[0] = p[1] = 1;
    int i, j;

    for(i = 4; i < MAX; i += 2)
    {
        p[i] = 1;
    }

    int sq = sqrt(MAX);

    for(i = 3; i < sq; i+=2)
    {
        if(p[i] == 1) continue;
        for(j = i*i; j < MAX; j += 2*i)
        {
            p[j] = 1;
        }
    }

}
int lengthOfNumber(int num)
{
    int count = 0;
    while(num > 0)
    {
        count++;
        num /= 10;
    }

    return count;
}
int reverse (int num)
{
    int len = lengthOfNumber(num), reversedNumber = 0;
    int div = 10, mul;
    double pw = (double)(len - 1);
    pw = pow(10.0, pw);
    mul = pw;

    while(len--)
    {
         int rem = num % 10;
         reversedNumber += (rem * mul);
         num /= 10;
         mul /= 10;
    }

    return reversedNumber;
}

int main (void)
{
    sieveMethod();
    long long int N;
    while(scanf("%lld", &N) == 1)
    {
        long long int t = reverse(N);
        if(t == N)
        {
            if(p[N] == 0) printf("%lld is prime.\n", N);
            else printf("%lld is not prime.\n", N);
        }

        else
        {
            if(p[N] == 0 && p[t] == 0) printf("%lld is emirp.\n", N);
            else if(p[N] == 0) printf("%lld is prime.\n", N);
            else printf("%lld is not prime.\n", N);
        }
    }

    return 0;
}
