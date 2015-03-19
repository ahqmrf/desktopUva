#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define maxN 1000001

int reverse(int num)
{
    char numChar[20];
    int i = 0;
    while(num)
    {
        numChar[i] = (num%10) + '0';
        i++;
        num/=10;
    }
    numChar[i] = '\0';
    return atoi(numChar);
}

int ifP(int num)
{
    if(num == 1 || num%2==0) return 0;
    int sqroot = sqrt(num);
    int i;
    for(i = 2; i<=sqroot;i++)
    {
        if(num%i==0) return 0;
    }
    return 1;
}

int main (void)
{
    int num;

    while(scanf("%d", &num)!=EOF)
    {
        if(ifP(num))
        {
            int rnum = reverse(num);
            if(ifP(rnum) && num!=rnum) printf("%d is emirp.\n", num);
            else printf("%d is prime.\n", num);
        }
        else printf("%d is not prime.\n", num);
    }
    return 0;
}
