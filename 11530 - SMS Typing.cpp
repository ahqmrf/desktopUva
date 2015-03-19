#include<iostream>
#include<string>

using namespace std;

int pressValue(char ch)
{
    if(ch == 'a'|| ch == ' ' || ch == 'd' || ch == 'g' || ch == 'j' || ch == 'm' || ch == 'p' || ch == 't' || ch == 'w') return 1;
    else if(ch == 'b'|| ch == 'e' || ch == 'h' || ch == 'k' || ch == 'n' || ch == 'q' || ch == 'u' || ch == 'x') return 2;
    else if(ch == 'c'|| ch == 'f' || ch == 'i' || ch == 'l' || ch == 'o' || ch == 'r' || ch == 'v'|| ch == 'y') return 3;
    else if(ch == 's'|| ch == 'z') return 4;
}


int main(void)
{
    int cases, case_no = 0;
    cin >> cases;
    string line;
    getline(cin, line);
    while(cases--)
    {
        string str;
        getline(cin, str);
        int count = 0;
        for(int i = 0; i < str.length(); ++i)
        {
            count += pressValue(str[i]);
        }

        cout << "Case #" << ++case_no << ": " << count << endl;
    }
    return 0;
}
