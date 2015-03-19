#include<bits/stdc++.h>

using namespace std;

int main()
{
	int sum, a, n;

	while (scanf("%d", &sum), sum != -1)
    {
		for (n = (int) sqrt(2 * sum); n > 0; n--)
        {
			if ((2*sum + n - n*n) % (2*n) == 0)
			{
				a = (2*sum + n - n*n) / (2*n);
				break;
			}
		}

		printf("%d = %d + ... + %d\n", sum, a, a + n - 1);
	}

	return 0;
}
