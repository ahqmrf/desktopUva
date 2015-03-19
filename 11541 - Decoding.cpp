#include<iostream>
#include<string>
#include<vector>
#include<sstream>


using namespace std;

int convert(string str)
{
    stringstream iss;

    iss << str;
    int number;
    iss >> number;
    return number;
}

int main (void)
{
    int cases;
    cin >> cases;
    int case_no = 0;
    string line;
    getline(cin, line);
    while(cases--)
    {
        string encoded;
        cin >> encoded;

        string number;
        vector<char> letter;
        vector<int> freq;

        for(int i = 0; i < encoded.length(); ++i)
        {
            if(encoded[i] >= 65 && encoded[i] <= 90)
            {
                if(i != 0) freq.push_back(convert(number));
                number = "";
                letter.push_back(encoded[i]);
            }

            else{
                number += encoded[i];
            }
        }

        freq.push_back(convert(number));

        cout << "Case " << ++case_no << ": ";

        for(int i = 0; i < letter.size(); ++i)
        {
            for(int j = 0; j < freq[i]; ++j)
            {
                cout << letter[i];

            }
        }

        cout << endl;
    }
    return 0;
}
