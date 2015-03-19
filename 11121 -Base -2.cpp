#include <cstdio>
#include <vector>

using namespace std;

int main()
{
	
	int cases;
	scanf("%d", &cases);
	for(int c = 1; c <= cases; c++)
	{
		vector<int>b;
		int num, r, base = -2;
		scanf("%d", &num);
		if(num == 0) b.push_back(0);
		while(!(num == 0 || num == 1))
		{
			if(num % base < 0)
			{
				int tnum = (num/base)+1;
				b.push_back(num - tnum*base);
				num = tnum;
			}
			else
			{
				b.push_back(num % base);
				num /= base;
			}
		}
		if(num > 0) b.push_back(num);
		printf("Case #%d: ",c);

		for(int i = b.size()-1; i>=0; i--) printf("%d", b[i]);
		puts("");
	}

	return 0;
	
}