#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return (b==0)?a:gcd(b,a%b);
}

int main()
{
    int nums[1001], g, n;
    while(scanf("%d", nums) && nums[0] != 0)
    {
        n = 1;
        while(scanf("%d", &nums[n]) && nums[n] != 0)
            n++;
        g = 0;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(nums[i]-nums[j] != 0)
                    g = gcd(abs(nums[i]-nums[j]), g);

        printf("%d\n",g);
    }
    return 0;
}
