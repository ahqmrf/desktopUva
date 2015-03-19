#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

int main (void)
{
    int n, t;
    scanf("%d%d", &n, &t);
    string hudai;
    getline(cin, hudai);
    map<string, string> loader;
    while(n--)
    {
        string a, b;
        cin >> a >> b;
        loader[a] = b;
    }

    while(t--)
    {
        string a;
        cin >> a;
        if(loader.find(a) != loader.end()) cout << loader[a] << endl;
        else
        {
            int l = a.length();
            if(a[l-1] == 'y') {
                if(a[l-2] == 'a' || a[l-2] == 'e' || a[l-2]=='u' || a[l-2] == 'o' || a[l-2] == 'i')
                {
                    a = a + "s";
                }
                else{
                    a[l-1] = 'i';
                    a = a + "es";
                }
            }

            else if(a[l-1] == 'o' || a[l-1] == 's' || a[l-1] == 'x')
            {
                a = a + "es";
            }

            else if(a[l-1] == 'h' && (a[l-2] == 's' || a[l-2] == 'c'))
            {
                a = a + "es";
            }
            else a = a + "s";
            cout << a << endl;
        }
    }
    return 0;
}
