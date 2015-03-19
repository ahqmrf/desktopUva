#include<iostream>
#include<string>

using namespace std;

int main (void)
{
    string str;
    int cases, c = 1, x, y;
    cin >> cases;
    while(cases--)
    {
        cin >> x >> str;
        y = (str.length()>3)? (int)str[3]-'0' : 0;
        cout << "Case " << c++ << ": " << x*0.5 + y*0.05 << endl;
    }
    return 0;
}
