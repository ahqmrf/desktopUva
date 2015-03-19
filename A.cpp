#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a, b, next;
    getline(cin, a);
    getline(cin, b);
    int sl = a.length();
    bool poss = true;
    for(int i=0; i<sl; i++)
    {
        if(i==sl-1 && (a[i] == b[i] || a[i]+1 == b[i]))
        {
            poss = false;
            break;
        }
        else if(a[i]==b[i] || a[i]+1==b[i]) next+=a[i];
        else if(b[i] - a[i] > 1)
        {
            next += a[i]+1;
            break;
        }

    }
    if(!poss) cout << "No such string" << endl;
    else
    {
        int nl = next.length();
        for(int i=0; i<sl-nl; i++)
        {
            next+='a';
        }
        cout << next << endl;
    }
    return 0;
}
