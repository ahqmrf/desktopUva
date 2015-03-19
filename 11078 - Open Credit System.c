#include <stdio.h>

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int i, j, max, ans = -2e9;
        scanf("%d", &max);
        for (i = 1; i < n; i++)
        {
            scanf("%d", &j);
            ans = max - j > ans ? max - j : ans;
            max = j > max ? j : max;
        }
        printf("%d\n", ans);
    }
    return 0;
}
