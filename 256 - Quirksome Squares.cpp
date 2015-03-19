#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	const int digit[] = {0, 10, 100, 1000, 10000};
	vector <int> qs[5];
	int x, sq, n, m;

	for(int i = 0; i < 10000; i++)
	{
		sq = i*i;
		for(int j = 1; j < 5; j++)
		{
			if(i < digit[j])
			{
				x = sq % digit[j] + sq/ digit[j];
				if(x == i) qs[j].push_back(sq);
			}
		}
	}

	while(scanf("%d", &n) == 1)
	{
		m = n >> 1;
		int s = qs[m].size();
		for(int i = 0; i < s; i++)
		{
			printf("%0*d\n", n, qs[m][i]);
		}
	}
	return 0;

}