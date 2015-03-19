#include <stdio.h>

int main()
{
	int x, N, max, ret;
	while(scanf("%d", &N) == 1) {
		int dP[110][110] = {0};
		int i, j, k, l;
		max = -2147483647;
		for(i = 1; i<=N; i++) {
			for(j = 1; j<=N; j++){
				scanf("%d", &x);
				dP[i][j] = dP[i-1][j] + dP[i][j-1] - dP[i-1][j-1] + x;
			}
		}

		for(i = 1; i<=N; i++)
			for(j = 1; j<=N; j++)
				for(k = 1; k<=i; k++)
					for(l = 1; l<=j; l++) {
						ret = dP[i][j] - dP[i][l-1] - dP[k-1][j] + dP[k-1][l-1];
						if(ret > max) max= ret;
					}
		printf("%d\n", max);
	}
	return 0;
}