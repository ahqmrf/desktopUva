#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxN 1100

int dp[maxN][maxN];
char s[maxN];

int max (int a, int b)
{
    return (a>b)? a : b;
}


int Longest_Palindrome(int lft, int rgt)
{
    if(lft==rgt)    return 1;
    if(lft>rgt) return 0;

    if(dp[lft][rgt]!=-1)    return dp[lft][rgt];

    int ret=0;
    if(s[lft]==s[rgt])
        ret=Longest_Palindrome(lft+1,rgt-1)+2;
    else
        ret=max(Longest_Palindrome(lft+1,rgt),Longest_Palindrome(lft,rgt-1));

return dp[lft][rgt]=ret;
}

int main ()
{
    int cases, sl;
    scanf("%d\n", &cases);
    while(cases--)
    {
        gets(s);
        memset(dp, -1, sizeof(dp));
        sl = strlen(s);
        printf("%d\n", Longest_Palindrome(0, sl-1));
    }
    return 0;
}
