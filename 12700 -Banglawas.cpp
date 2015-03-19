#include<map>
#include<iostream>

using namespace std;

int main (void)
{
    int cases, nom, i = 1;
    char ch;
    cin >> cases;
    while(cases--)
    {
        map<char, int> M;
        M['A'] = 0;
        M['B'] = 0;
        M['W'] = 0;
        M['T'] = 0;

        cin >> nom;

        for(int j = 0; j < nom; j++)
        {
            cin >> ch;
            M[ch]++;
        }

        cout << "Case " << i++ << ": ";
        if(nom == M['A']) cout << "ABANDONED" << endl;
        else if(nom - M['A'] == M['B'] && M['T'] == 0) cout << "BANGLAWASH" << endl;
        else if(nom - M['A'] == M['W'] && M['T'] == 0) cout << "WHITEWASH" << endl;
        else if(M['B'] > M['W']) cout << "BANGLADESH " << M['B'] << " - " << M['W'] <<  endl;
        else if(M['B'] < M['W']) cout << "WWW " << M['W'] << " - " << M['B'] << endl;
        else cout << "DRAW " << M['B'] <<" " <<  M['T'] << endl;
    }
    return 0;
}
