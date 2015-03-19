#include<cstdio>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

int main (void)
{
    int cases, num, sum, n;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &num);
        stringstream ss;
        string s;
        ss << num;
        ss >> s;
        n = s.length();
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            int d = s[i] - '0';
            double value = pow(d, n);
            sum += (int)value;
        }

        if(sum == num) printf("Armstrong\n");
        else printf("Not Armstrong\n");
    }

    return 0;
}
