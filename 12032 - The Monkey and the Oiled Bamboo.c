#include <stdio.h>
int main()
{
	int cases, tc, n, k, i, ans;
	scanf("%d", &cases);
	for(tc = 1; tc <= cases; tc++)
	{
		scanf("%d", &n);
		int a[100001] = {0};
		k = 0;
		for(i = 1; i <= n; i++)
		{
			scanf("%d", a+i);
			if(a[i] - a[i-1] > k)
				k = a[i] - a[i-1];
		}
		ans = k;
		for(i = 1; i <= n; i++)
		{
			if(a[i]-a[i-1] == k) k--;
			else if(a[i]-a[i-1] > k)
			{
				ans++;
				break;
			}
		}

		printf("Case %d: %d\n", tc, ans);
	}
	return 0;
}