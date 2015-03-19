#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
using namespace std;

int main ()
{
    string longest = "", str;
    while(cin >> str && str != "E-N-D")
    {
        string clean;
        for(int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if(!((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || ch =='-')) str[i] = ' ';
        }

        istringstream iss(str);
        while(iss >> clean){
            if(clean.length() > longest.length()) longest = clean;
        }
    }
    for(int i = 0; i < longest.length(); i++)
    {
        longest[i] = tolower(longest[i]);
    }

    cout << longest << endl;


    return 0;
}
