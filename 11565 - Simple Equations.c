#include <stdio.h>
 
int a, b, c, x, y, z;
void solve()
{
	int t = a;
	if(b != 0) t = b;
	for(x = -t; x <= t; x++)
	{
		if(x && b%x) continue;
		for(y = x+1; y <= t; y++)
		{
			if(y && b%y) continue;
			z = a-x-y;
			if(y >= z) continue;
			if(x+y+z == a && x*y*z == b && x*x+y*y+z*z == c)
			{
				printf("%d %d %d\n", x, y, z);
				return;
			}
		}
	}
	puts("No solution.");
}

int main()
{
	int cases;
	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%d %d %d", &a, &b, &c);
		solve();
	}
	return 0;
}

