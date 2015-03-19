#include<string>
#include<iostream>
#include<cstring>
using namespace std;

bool exist(char ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'o' || ch =='i' || ch == 'u') return true;
    else return false;
}

int main (void)
{
    string s[3];
    int three = 3;
    int count[3];
    memset(count, 0, sizeof(count));
    for(int i = 0; i < 3; i++)
    {
        getline(cin, s[i]);
        for(int j = 0; j < s[i].size(); j++)
        {
            if(exist(s[i][j])) count[i]++;
        }
    }


    if(count[0]==5 && count[1]==7 && count[2]==5) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
