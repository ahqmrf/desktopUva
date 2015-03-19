#include<map>
#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main (void)
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int n, p;
        int count = 0;
        map<int, bool> myMap;
        vector<int> days;
        scanf("%d %d", &n, &p);
        while(p--)
        {
            int day;
            scanf("%d", &day);

            if(myMap.find(day) == myMap.end())
            {
                myMap[day] = true;
                days.push_back(day);
                for(int i = 2; ; i++)
                {
                    int d = day*i;
                    if(d > n) break;

                    if(myMap.find(d) == myMap.end()){
                        myMap[d] = true;
                        days.push_back(d);
                    }
                }
            }

        }

        int l = days.size();
        for(int i = 0; i < l; i++)
        {
            if(days[i] % 7 == 6 || days[i] % 7 == 0) continue;
            else count++;
        }

        printf("%d\n", count);

    }
    return 0;
}
