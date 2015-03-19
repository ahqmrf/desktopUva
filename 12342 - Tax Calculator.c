#include<stdio.h>
#include<math.h>
int main() 
{
	int T, C = 0, k;
	scanf("%d", &T);
	while(T--) 
	{
		scanf("%d", &k);
		printf("Case %d: ", ++C);
		double tax = 0;
		if(k > 180000) 
		{
			k -= 180000;
			if(k > 0) 
			{
				tax += (k >= 300000 ? 300000 : k)*0.1;
				k -= 300000;
				if(k > 0) 
				{
					tax += (k >= 400000 ? 400000 : k)*0.15;
					k -= 400000;
					if(k > 0) 
					{
						tax += (k >= 300000 ? 300000 : k)*0.2;
						k -= 300000;
						if(k > 0)
							tax += k*0.25;
					}
				}
			}
			if(tax < 2000) puts("2000");
			else	printf("%d\n", (int)ceil(tax));
		} 
		else puts("0");
	}
	return 0;
}