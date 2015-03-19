#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

int main (void)
{

    while(true)
    {
        int G;
        scanf("%d", &G);
        if(!G) break;
        string str;
        cin >> str;

        int groupLength = str.length() / G;
        int lowestIndex = 0;
        int highestLimit = groupLength;
        while(G--)
        {
            for(int i = highestLimit-1; i >= lowestIndex; i--)
            {
                cout << str[i];
            }

            highestLimit += groupLength;
            lowestIndex += groupLength;
        }

        cout << endl;

    }
    return 0;
}
