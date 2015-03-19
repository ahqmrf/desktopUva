#include<sstream>
#include<iostream>
#include<string>

using namespace std;

string intIntoStr(int num)
{
    stringstream ss;
    ss << num;
    string str = ss.str();
    return str;
}

int sumOfDigit(string str)
{
    int sum = 0;
    for(int i = 0; i< str.length(); ++i)
    {
        int digit = str[i] - '0';
        sum += digit;
    }
    return sum;
}

int main()
{
    while(1)
    {
        string str;
        cin >> str;
        if(str == "0") break;
        while(1)
        {
            if(str.length() == 1) break;
            int sum = sumOfDigit(str);
            str = intIntoStr(sum);

        }
        cout << str << endl;

    }
    return 0;
}

