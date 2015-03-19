#include <iostream>
#include <algorithm>
#include<vector>
#include<string>

using namespace std;

int main ()
{
    string a;
    int cases, n;
    cin >> cases;
    while(cases--)
    {
        cin >> a;
        cin >> n;

        sort(a.begin(), a.end());
        int l = a.length();
        int m = 0;

        do {
            string cs;
            for(int i = 0; i<l; i++)
                cs+= a[i];
            if(m == n) cout << cs << endl;
            m++;

        } while (next_permutation(a.begin(),a.end()));

    }

    return 0;
}


