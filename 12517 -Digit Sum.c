#include <stdio.h>
#include <math.h>
#include <string.h>
#define int64 long long int

int64 sum(char num[])
{
	int n = atoi(num);

	int i, j, r, q, k, t = 0;
	int64 n45 = 45;
	int nod = strlen(num);
	int64 ret = 0;
	for(j=1; j<nod; j++){
		int p = (int)pow(10, j);
		ret += (n/p) * n45;
		n45*=10;
	}

	for(j=0, k = nod-1; j<nod; j++, k--){
		int p = (int)pow(10, j);
		int c = num[k]-48;
		for(i=1; i<c; i++){
			ret += i*p;
		}

		ret += c*(t+1);
		t = n%(p*10);
	}

	return ret;

}

int main()
{
	char num[12];
	char n[12];
	while(scanf("%s %s", n, num) == 2) {
		
		if(!strcmp(num, "0") && !strcmp(n, "0")) break;
		
		int64 ret = sum(num) - sum(n);
		int i, s = strlen(n);
		for(i=0; i<s; i++)
			ret += (n[i]-48);
		printf("%lld\n", ret);
		
	}


	return 0;
}