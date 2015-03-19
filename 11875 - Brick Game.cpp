#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

int main (void)
{
    int cases, n, half, age;
    scanf("%d", &cases);
    for(int i = 1; i <= cases; i++)
    {
        vector<int> ages;
        scanf("%d", &n);
        half = n/2;
        while(n--)
        {
            scanf("%d", &age);
            ages.push_back(age);
        }
        sort(ages.begin(), ages.end());
        printf("Case %d: %d\n", i, ages[half]);

    }
    return 0;
}
