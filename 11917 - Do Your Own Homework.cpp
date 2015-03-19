#include<iostream>
#include<string>
#include<map>

using namespace std;

int main (void)
{
    int cases;
    cin >> cases;
    for(int i = 1; i <= cases; i++)
    {
        int n, sday;
        string sub;
        map<string, int> M;
        cin >> n;
        while(n--)
        {
            cin >> sub >> sday;
            M[sub] = sday;
        }

        cin >> n;
        cin >> sub;
        cout << "Case " << i << ": ";
        if(M.find(sub) == M.end()) cout << "Do your own homework!" << endl;
        else {
            if(M[sub] <= n) cout << "Yesss" << endl;
            else if(M[sub] <= n+5)cout << "Late" << endl;
            else cout << "Do your own homework!" << endl;
        }
    }
    return 0;
}
