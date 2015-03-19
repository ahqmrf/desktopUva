#include <stdio.h>
int main()
{
	int mile, juice, n, duration, cases, i;
	scanf("%d", &cases);
	for(i = 1; i <= cases; i++)
	{
		scanf("%d", &n);
		mile = juice = 0;
		while(n--)
		{
			scanf("%d", &duration);
			mile += 10*(duration/30) + 10;
			juice += 15*(duration/60) + 15;
		}
		printf("Case %d: ", i);
		if(mile == juice) printf("Mile Juice %d\n", mile);
		else if(mile > juice) printf("Juice %d\n", juice);
		else printf("Mile %d\n", mile);
	}

	return 0;
}