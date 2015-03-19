#include<iostream>
#include<string>

using namespace std;

bool vowel(char ch)
{
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    else return false;
}

int main (void)
{
    int cases;
    cin >> cases;
    string real, abstract;
    while(cases--)
    {
        cin >> real >> abstract;
        if(real.length() == abstract.length())
        {
            bool flag = true;
            int l = real.length();
            for(int i = 0; i < l; i++)
            {
                if(vowel(real[i]))
                {
                    if(vowel(abstract[i]))
                    {
                        abstract[i] = real[i];
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
            }

            if(flag)
            {
                if(real == abstract) cout << "Yes" << endl;
                else cout << "No" << endl;
            }

            else cout << "No" << endl;


        }

        else cout << "No" << endl;
    }
    return 0;
}
