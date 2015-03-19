#include<vector>
#include<cstdio>
#include<cstring>
#include<map>

using namespace std;

int main (void)
{
    char image[100][100];
    int R, C, M, N, maxF, cases, total;
    scanf("%d", &cases);
    for(int c = 1; c <= cases; c++)
    {
        scanf("%d %d %d %d", &R, &C, &M, &N);
        total = R * C;
        int freq[26];
        memset(freq, 0, sizeof(freq));
        for(int i=0; i<R; i++)
        {
            scanf("%s", image[i]);
            for(int j=0; j<C; j++)
            {
                freq[image[i][j]-'A']++;
            }
        }
        maxF = 0;
        int important = 0;
        for(int i=0; i<26; i++) if(freq[i]>maxF) maxF = freq[i];
        for(int i=0; i<26; i++) if(freq[i]==maxF) important++;


        printf("Case %d: %d\n", c, important*M*maxF + (total-(important*maxF))*N);

    }
    return 0;
}
