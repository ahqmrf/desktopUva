#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define LL long long
int main (void)
{
    int N, c = 1;
    while(scanf("%d", &N) != EOF){

        int arr[20];
        vector<long long> gunfols;
        for(int i = 0; i < N; i++){
            scanf("%d", &arr[i]);
            gunfols.push_back(arr[i]);
        }
        if(N == 1) {
            if(arr[0] > 0) printf("Case #%d: The maximum product is %d.\n\n", c, arr[0]);
            else printf("Case #%d: The maximum product is 0.\n\n", c);
        }

        else
        {


            for(int i = 0; i < N; i++)
            {
                long long pro = arr[i];

                for(int j = 1+i; j < N; j++)
                {
                    pro *= arr[j];
                    gunfols.push_back(pro);
                }
            }
            sort(gunfols.begin(), gunfols.end());
            int s = gunfols.size() -1;
            if(gunfols[s] < 0) printf("Case #%d: The maximum product is 0.\n\n", c);
            else printf("Case #%d: The maximum product is %lld.\n\n", c, gunfols[s]);
        }
        c++;
    }
    return 0;
}
