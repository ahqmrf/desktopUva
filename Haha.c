#include<stdio.h>
#include<string.h>

int main (void)
{
    int i, c;
    long long Factorial[21];
    Factorial[0] = Factorial[1] = 1;
    for(i=2; i<=20; ++i)
    {
        Factorial[i] = Factorial[i-1]*i;
    }
    char word[25];
    int cases;
    scanf("%d\n", &cases);
    for(c=1; c<=cases; c++)
    {
        gets(word);
        int length = strlen(word), j;
        long long ans = Factorial[length];
        for(i=0; i<length-1; i++)
        {
            int count = 1;
            for(j=i+1; j<length; j++)
            {
                if(word[i]==word[j]) count++;
            }
            ans /= Factorial[count];
        }

        printf("Data set %d: %lld\n", c, ans);
    }
    return 0;
}
