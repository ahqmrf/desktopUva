#include <stdio.h>
int main()
{
	int N, B, H, W, p, a, cost, i;
	while(scanf("%d %d %d %d", &N, &B, &H, &W) == 4)
	{
		cost = B + 1;
		while(H--)
		{
			scanf("%d", &p);
			for(i = 0; i < W; i++)
			{
				scanf("%d", &a);
				if(a >= N && N*p < cost)
					cost = N*p;
			}
		}
		(cost == B+1)? puts("stay home") : printf("%d\n", cost);
	}
	return 0;
}