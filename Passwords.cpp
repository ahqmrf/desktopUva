#include<string>
#include<iostream>
#include<vector>

using namespace std;

int main ()
{
    int N, M;
    while(cin >> N)
    {
        vector<string> dictionary, rules, pass;

        string word, rule;
        for(int i = 0; i < N; i++)
        {
            cin >> word;
            dictionary.push_back(word);
        }

        cin >> M;

        for(int i = 0; i < M; i++)
        {
            cin >> rule;
            rules.push_back(rule);
        }

        for(int i = 0; i < M; i++)
        {
            for(int j = 0; j < N; j++)
            {
                int P = rules[i].length();
                for(int k = 0; k < P; k++)
                {

                }
            }
        }
    }
    return 0;
}
