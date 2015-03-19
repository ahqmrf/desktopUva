#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define maxN 50
#define uint64 unsigned long long int

using namespace std;

uint64 fibonacci[maxN], code[maxN];
map<uint64, int> nth;

int main()
{
	fibonacci[0] = 1, fibonacci[1] = 2;
	nth[1] = 0, nth[2] = 1;
	for(int i = 2; i<maxN; i++)
	{
		fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
		nth[fibonacci[i]] = i;
	}

	
	int cases;
	scanf("%d", &cases);
	while(cases--)
	{
		int N;
		uint64 maximum = 0;
		scanf("%d", &N);
		for(int i=0; i<N; i++)
		{
			scanf("%llu", &code[i]);
			if(code[i] > maximum) maximum = code[i];
		}
		int len = nth[maximum];
		char output[110], text[110];
		for(int i=0; i<len; i++)
		{
			output[i] = ' ';
		}
		int c = 0;
		getchar();
		char ch;
		while(scanf("%c", &ch))
		{
			if(ch=='\n') break;
			if(ch >= 65 && ch <= 90)
			{
				text[c] = ch;
				c++;	
			}
			
		}
		text[c] = '\0';
		
		for(int i=0; i<N; i++)
		{
			output[nth[code[i]]] = text[i];			
		}
		output[len+1] = '\0';

		printf("%s\n", output);
	}

	return 0;
}


