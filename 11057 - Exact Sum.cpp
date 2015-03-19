#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

int main (void)
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        map<int, bool> cost;
        for(int i = 0; i < n; i++)
        {
            int value;
            scanf("%d", &value);
            if(cost.find(value) == cost.end()) cost[value] = false;
            else cost[value] = true;
        }

        int sum;
        scanf("%d", &sum);

        int item = sum/2;
        for(int i = item; i >= 0; i--)
        {
            if(cost.find(i) != cost.end() && cost.find(sum-i) != cost.end())
            {
                if(i == sum-i && cost[i] == true){
                    printf("Peter should buy books whose prices are %d and %d.\n\n", i, sum-i);
                    break;
                }

                else if(i == sum-i && cost[i] == false) continue;
                else {
                    printf("Peter should buy books whose prices are %d and %d.\n\n", i, sum-i);
                    break;
                }


            }


        }

        cost.clear();
    }
    return 0;
}
