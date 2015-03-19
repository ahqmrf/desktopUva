#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int Lcm(int a, int b)
{
	return (a*b)/gcd(a, b);
}

int main()
{
	int cases, mod, divisor, lcm, nof, len, i;
	char number[1010];
	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%s", number);
		scanf("%d", &nof);
		lcm = 1;
		while(nof--)
		{
			scanf("%d", &divisor);
			lcm = Lcm(lcm, divisor);
		}
		
		len = strlen(number);
		mod = 0;
		for(i = 0; i < len; i++)
		{
			mod = (mod*10 + number[i]-'0')%lcm;
		}
		mod? printf("%s - Simple.\n", number) : printf("%s - Wonderful.\n", number);
	}
	return 0;
}