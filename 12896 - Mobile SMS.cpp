#include<map>
#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int main (void)
{
    map<int, string> M;
    M[0] = " ";
    M[1] = ".,?\"";
    M[2] = "abc";
    M[3] = "def";
    M[4] = "ghi";
    M[5] = "jkl";
    M[6] = "mno";
    M[7] = "pqrs";
    M[8] = "tuv";
    M[9] = "wxyz";
    int cases;
    scanf("%d", &cases);
    int a[10000], c[10000], n, i;
    while(cases--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        for(i = 0; i < n; i++)
        {
            scanf("%d", &c[i]);
        }

        for(i = 0; i < n; i++)
        {
            printf("%c", M[a[i]][c[i]-1]);
        }

        printf("\n");


    }
    return 0;
}
