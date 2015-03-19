#include<map>
#include<iostream>
using namespace std;

int main (void)
{
    string s;
    map<string, string> m;
    m["HELLO"] = "ENGLISH";
    m["HOLA"] = "SPANISH";
    m["HALLO"] = "GERMAN";
    m["BONJOUR"] = "FRENCH";
    m["CIAO"] = "ITALIAN";
    m["ZDRAVSTVUJTE"]= "RUSSIAN";
    int i = 1;
    while(cin >> s)
    {
        if(s[0] == '#') break;
        if(m.find(s) == m.end()) cout << "Case " << i++ << ": UNKNOWN" << endl;
        else cout << "Case " << i++ << ": " << m[s] << endl;
    }
    return 0;
}
