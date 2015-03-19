#include<bits/stdc++.h>

using namespace std;

int main()
{
    int cases;
    scanf("%d",&cases);
    getchar();
    for(int c = 1; c<=cases; c++)
    {
        string judge, programmer;
        getline(cin, programmer);
        getline(cin, judge);

        printf("Case %d: ", c);
        if(judge == programmer) puts("Yes");
        else
        {
            string tjudge, tpro;
            for(int i=0; i<judge.length(); i++)
            {
                if(judge[i] == ' ') continue;
                tjudge += judge[i];
            }

            for(int i=0; i<programmer.length(); i++)
            {
                if(programmer[i] == ' ') continue;
                tpro += programmer[i];
            }

            if(tpro == tjudge) puts("Output Format Error");
            else puts("Wrong Answer");
        }
    }
    return 0;
}
