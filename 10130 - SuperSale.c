#include <stdio.h>
#include <string.h>

int main()
{
	int cases;
	scanf("%d", &cases);
	while(cases--) {
		int N;
		scanf("%d", &N);
		int dP[35], w, value, i;
		memset(dP, 0, sizeof dP);
		while(N--) {
			scanf("%d %d", &value, &w);
			for(i = 32; i >= 0; i--) {
				if(w <= i && dP[i] < dP[i-w]+value)
					dP[i] = dP[i-w] + value;
			}
		}
		int max = 0;
		scanf("%d", &N);
		while(N--) {
			scanf("%d", &w);
			max += dP[w];
		}
		printf("%d\n", max);
	}
	return 0;
}