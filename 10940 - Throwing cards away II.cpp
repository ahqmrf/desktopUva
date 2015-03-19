#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main (void)
{
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        if(n == 1) printf("1\n");
        else if(n == 2 || n == 3) printf("2\n");
        else
        {
            vector<int> deck;
            for(int i = 1; i <= n; i++)
            {
                deck.push_back(i);
            }

            int len = n, m = 1;

            while(n != 2)
            {
                int card = deck[m];
                deck.push_back(card);
                len++;
                n--;
                m += 2;
            }

            len--;
            printf("%d\n", deck[len]);
        }
    }
    return 0;
}
