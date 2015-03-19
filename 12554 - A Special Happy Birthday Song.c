#include<stdio.h>
#include<string.h>
#include<math.h>
int main (void)
{
    char song[16][100] = {"Happy","birthday","to","you","Happy","birthday",
    "to","you","Happy","birthday","to","Rujia","Happy","birthday","to","you"};
    char names[101][100];
    int n, i, j, k, l;
    while(scanf("%d", &n) == 1)
    {
        l = 1;
        for(i = 0; i<n; i++) scanf("%s", names[i]);
        if(n > 16) l = ceil(n/16)+1;
        for(i = 0, j = 0, k = 0; i<16*l; i++, j++, k++)
        {
            if(i == 16) k = 0;
            if(j == n) j = 0;
            printf("%s: %s\n", names[j], song[k]);
        }
    }
    return 0;
}
