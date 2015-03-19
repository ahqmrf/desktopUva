#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cases;
	scanf("%d", &cases);
	while(cases--)
	{
		int n, x, low = 0;
		long long ret = 0;
		map <int, int> R;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			int &y = R[x];
			if(y > low) low = y;
			y = i;
			ret += i - low;
		}
		printf("%lld\n", ret);
	}
	return 0;
}