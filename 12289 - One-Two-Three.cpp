#include<iostream>
#include<string>
#include<algorithm>


using namespace std;

string deleteChar(string str, int pos)
{
    string sen;
    for(int i = 0; i < str.length(); i++)
    {
        if(i != pos) sen += str[i];
    }
    return sen;
}

int main (void)
{
    int n;
    cin >> n;
    string hudai;
    getline(cin, hudai);
    while(n--)
    {
        string letter;
        getline(cin, letter);
        if(letter.length() == 5) cout << "3" << endl;
        else
        {
            if((letter[0] == 'o' && letter[1] == 'n') || (letter[0] == 'o' && letter[2] == 'e') || letter[1] == 'n' && letter[2] == 'e')
            {
                cout << "1" << endl;
            }
            else cout << "2" << endl;
        }

    }
    return 0;
}
