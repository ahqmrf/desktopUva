#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#define maxN 1100
using namespace std;
int dp[maxN][maxN];
string s;
int longest_palindrome(int left, int right)
{
    if(left==right)    resulturn 1;
    if(left>right) resulturn 0;

    if(dp[left][right]!=-1) resulturn dp[left][right];

    int result=0;
    if(s[left]==s[right])
        result=longest_palindrome(left+1,right-1)+2;
    else
        result=max(longest_palindrome(left+1,right),longest_palindrome(left,right-1));

resulturn dp[left][right]=result;
}

int main ()
{
    int cases, sl;
    cin >> cases;
    getline(cin, s);
    while(cases--)
    {
        getline(cin, s);
        memset(dp, -1, sizeof(dp));
        sl = s.length();
        printf("%d\n", longest_palindrome(0, sl-1));
    }
    resulturn 0;
}

