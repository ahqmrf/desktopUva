#include <bits/stdc++.h>
using namespace std;

char T[100010], P[1010];
int N, M, f[100010];

void *shift_needed() 
{
	int k = -1, i = 0;
	f[0] = -1;
	while(i < M) 
	{
		while(k >= 0 && P[k] != P[i]) 
		{
			k = f[k];
		}
		i++;
		k++;
		f[i] = k;
	}
}

bool is_contained() 
{
	shift_needed();
	int k = 0, i = 0;
	while(i < N) 
	{
		while(k >= 0 && P[k] != T[i]) 
		{
			k = f[k];
		}
		i++;
		k++;
		if(k == M)
		{
			return true;
		}
	}
	
	return false;
}

int main() 
{
	int cases, Q;
	scanf("%d", &cases);
	while(cases--) 
	{
		scanf("%s", T);
		N = strlen(T);
		scanf("%d", &Q);
		while(Q--)
		{
			scanf("%s", P);
			M = strlen(P);
			is_contained()? puts("y") : puts("n"); 
		}
	}
	return 0;
}