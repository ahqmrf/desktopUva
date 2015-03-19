#include<map>
#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int main (void)
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        map<char, double>m;
        int M;
        cin >> M;
        while(M--)
        {
            char ch;
            double d;
            cin >> ch >> d;
            m[ch] = d;
        }

        cin >> M;
        getchar();
        double sum = 0.0;
        while(M--)
        {
            string s;
            getline(cin, s);
            for(int i=0; i<s.length(); i++)
            {
                if(m.find(s[i]) == m.end()) continue;
                sum+= m[s[i]];
            }
        }

        sum /= 100;
        printf("%.2lf$\n", sum);
    }
}
