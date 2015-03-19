#include<iostream>
#include<string>
using namespace std;

int main (void)
{
    int n;
    string s;
    while(cin >> n >> s)
    {
        int m = n/ 2;
        bool flag = true;

        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < m; i++)
        {
            if(s[i] == '4' || s[i] == '7') sum1 += (s[i] - '0');

            else {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            for(int i = m; i < n; i++)
            {
                if(s[i] == '4' || s[i] == '7') sum2 += (s[i] - '0');

                else {
                    flag = false;
                    break;
                }
            }
        }

        if(flag)
        {
            if(sum1 == sum2) cout << "YES" << endl;
            else cout << "NO" << endl;
        }

        else cout << "NO" << endl;
    }

    return 0;
}
