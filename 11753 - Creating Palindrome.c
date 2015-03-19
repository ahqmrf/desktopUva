#include <stdio.h>
#define int64 long long int
#define maxN 10010

int64 array[maxN];
int k;

int min(int a, int b)
{
	return a > b? b:a; 
}

int difficulty(int i, int j, int count)
{
	if(i > j) return count;
	if(count > k) return count;
	if(array[i] == array[j]) return difficulty(i+1, j-1, count);
	return min(difficulty(i+1, j, count+1), difficulty(i, j-1, count+1));
}

int main()
{
	int cases, N, i, count, c;
	scanf("%d", &cases);
	for(c = 1; c <= cases; c++)
	{
		scanf("%d %d", &N, &k);
		for(i = 0; i < N; i++)
			scanf("%lld", &array[i]);
		count = difficulty(0, N-1, 0);
		printf("Case %d: ", c);
		if(count > k) puts("Too difficult");
		else if(count == 0) puts("Too easy");
		else printf("%d\n", count);
	}
	return 0;

}