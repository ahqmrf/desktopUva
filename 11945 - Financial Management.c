#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "en_US.UTF-8");
	int cases, i, j;
	double money, sum;
	scanf("%d", &cases);
	for(i = 1; i <= cases; i++)
	{
		sum = 0;
		for(j = 0; j < 12; j++)
		{
			scanf("%lf", &money);
			sum += money;
		}
		printf("%d $%'.2lf\n", i, sum/12.0);
	}

	return 0;
}