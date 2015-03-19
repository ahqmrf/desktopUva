#include <stdio.h>
#include <math.h>

int number_of_digits(int N)
{
	int count = 1;
	while(N > 9)
	{
		count++;
		N /= 10;
	}
	return count;
}

int reverse(int N)
{
	int ex = (int)pow(10, number_of_digits(N) - 1), r = 0;
	while(N)
	{
		r += ex*(N%10);
		N /= 10;
		ex /= 10;
	}
	return r;
}

int isprime(int N)
{
	if(N%2 == 0) return 0;
	int sq = sqrt(N), i;
	for(i = 2; i <= sq; i++)
	{
		if(N%i == 0) return 0;
	}
	return 1;
}

int main()
{
	int N;
	while(scanf("%d", &N) != EOF)
	{
		if(isprime(N))
		{
			int r = reverse(N);
			if(r == N) printf("%d is prime.\n", N);
			else if(isprime(r)) printf("%d is emirp.\n", N);
			else printf("%d is prime.\n", N);
		}
		else printf("%d is not prime.\n", N);
	}
	return 0;
}