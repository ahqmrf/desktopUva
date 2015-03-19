#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main (void)
{
    int cases;
    cin >> cases;
    string line;
    getline(cin, line);
    while(cases--)
    {
        string input;
        getline(cin, input);
        vector<char>listOfChars;

        int frequency[26] = {0};

        for(int i = 0; i < input.length(); ++i)
        {
            if((input[i] <= 122 && input[i] >= 97) || (input[i] >= 65 && input[i] <=90))
            {
                int index;
                int ascii = input[i];

                if(ascii <= 90) ascii += 32;

                index = ascii - 97;

                frequency[index]++;
            }


        }

        int maxFreq = 1;


        for(int i = 0; i < 26; ++i)
        {
            if(maxFreq < frequency[i] && frequency[i])
            {
                listOfChars.clear();
                maxFreq = frequency[i];
                char ch = 'a' + i;
                listOfChars.push_back(ch);
            }

            else if(maxFreq == frequency[i] && frequency[i])
            {
                maxFreq = frequency[i];
                char ch = 'a' + i;
                listOfChars.push_back(ch);
            }
        }

        sort(listOfChars.begin(), listOfChars.end());
        for(int i = 0; i < listOfChars.size(); ++i)
        {
            cout << listOfChars[i];
        }

        cout << endl;
    }

    return 0;

}
