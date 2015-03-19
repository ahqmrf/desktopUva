#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

int main (void)
{
    int n;
    while(cin >> n, n)
    {
        int Max = -1;
        map<string, int>counts;
        for(int i = 0; i < n; i++)
        {
            string s, a[5];
            cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
            sort(a, a+5);
            for(int j = 0; j < 5; j++)
            {
                s += a[j];
            }

            if(!counts.count(s))
            {
                counts[s] = 1;
                Max = max(Max, 1);
            }

            else
            {
                int p = counts[s] + 1;
                counts[s] = p;
                Max = max(Max, p);
            }

        }

        int count = 0;
		map<string, int>::iterator it;
		for (it = counts.begin(); it != counts.end(); it++) {
			if (it->second == Max)
				count += it->second;
		}

		printf("%d\n", count);



    }
    return 0;
}
