#include<string>
#include<iostream>

using namespace std;

int main (void)
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        string str, sbstr;
        int q;
        cin >> str;
        cin >> q;
        while(q--)
        {
            cin >> sbstr;
            std::size_t found = str.find(sbstr);
            if(found==std::string::npos) cout << "n" << endl;
            else cout << "y" << endl;
        }
    }
    return 0;
}
