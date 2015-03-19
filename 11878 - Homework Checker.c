#include <stdio.h>
#include <string.h>

int main()
{
	char statement[200];
	int count = 0;
	while(scanf("%s", statement) != EOF)
	{
		int len = strlen(statement);
		if(statement[len-1] == '?') continue;
		int a[3] = {0}, i, j = 0, k = 0;
		char sign[2];
		for(i = 0; i < len; i++)
		{
			if(statement[i] <= '9' && statement[i] >= '0')
			{
				a[j] = a[j]*10 + statement[i]-'0';
			}
			else
			{
				sign[k] = statement[i];
				j++, k++;
			}
		}
		int c;
		if(sign[0] == '+') c = a[0]+a[1];
		else c = a[0]-a[1];
		if(c == a[2]) count++;
	}
	printf("%d\n", count);
	return 0;
}