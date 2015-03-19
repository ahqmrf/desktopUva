#include <string.h>
#include <stdio.h>

int main()
{
	char card[20];
	int i, j, digit, cases;
	scanf("%d\n", &cases);
	while(cases--)
	{
		gets(card);
		int sum = 0;
		for(i = 0, j = 0; card[i]; i++)
		{
			if(card[i] == ' ') continue;
			if(j%2) sum += (card[i]-'0');
			else
			{
				digit = card[i]-'0';
				digit*=2;
				sum += digit%10 + digit/10;
			}
			j++;
		}
		(sum%10)? puts("Invalid") : puts("Valid");
	}
	return 0;
}