#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main (void)
{
    int cases;
    cin >> cases;
    for(int i = 1; i <= cases; i++)
    {
        int Max = -2147483647;
        vector<string> web;
        string website;
        int relevance;
        for(int j = 0; j < 10; j++)
        {
            cin >> website >> relevance;
            if(relevance > Max)
            {
                web.clear();
                web.push_back(website);
                Max = relevance;
            }

            else if(relevance == Max)
            {
                web.push_back(website);
            }
        }

        int len = web.size();
        cout << "Case #" << i << ":" << endl;
        for(int j = 0; j < len; j++)
        {
            cout << web[j] << endl;
        }
    }
    return 0;
}
