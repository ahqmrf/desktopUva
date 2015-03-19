#include<bits/stdc++.h>
#include<cstring>

using namespace std;

int dP[1010][1010];
char str[1010];

int LPS(int i, int j)
{
    if(i == j) return 1;
    if(i > j) return 0;
    if(dP[i][j]!=-1) return dP[i][j];
    int ret;
    if(str[i] == str[j]) ret = 2+LPS(i+1, j-1);
    else ret = max(LPS(i+1, j), LPS(i, j-1));
    return dP[i][j] = ret;
}

int main()
{
    int cases;
    scanf("%d\n", &cases);
    while(cases--)
    {
        gets(str);
        memset(dP, -1, sizeof dP);
        printf("%d\n", LPS(0, strlen(str)-1));
    }
    return 0;
}
