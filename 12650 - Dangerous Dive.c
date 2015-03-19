#include <stdio.h>
#include <string.h>

int dnr[10010];
int main()
{
	int N, R;
	while(scanf("%d %d", &N, &R) == 2) {
		memset(dnr, 1, sizeof dnr);
		while(R--) {
			int id;
			scanf("%d", &id);
			dnr[id-1] = 0;
		}
		int i, found = 0;
		for(i = 0; i<N; i++) {
			if(dnr[i]) {
				printf("%d ", i+1);
				found = 1;
			}
		}
		if(!found) printf("*");
		puts("");
	}
	return 0;
}