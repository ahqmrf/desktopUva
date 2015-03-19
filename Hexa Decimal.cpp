#include<iostream>
#include<string>
#include<map>
#include<cmath>


using namespace std;

map<char, int> hexaMap;

string decimalIntoBinary(int num)
{
    string binaryString;
    while(num > 0)
    {
        char ch = (num%2) + '0';
        binaryString = ch + binaryString;
        num /= 2;
    }

    int len = binaryString.length();
    if(len < 13)
    {
        for(int i = 0; i < 13-len; i++)
        {
            binaryString = "0" + binaryString;
        }
    }
    return binaryString;
}

int hexaIntoDecimal(string hexa)
{
    int len = hexa.length();
    int decimal = 0;
    double pw = 0.00000000;
    for(int i = len-1; i >= 0; i--)
    {
        double d = pow(16, pw);
        int value = d;
        decimal += (hexaMap[hexa[i]] * value);
        pw = pw + 1.00000000;
    }
    return decimal;
}

int main (void)
{
    for(char i = '0'; i <= '9'; i++)
    {
        hexaMap[i] = (i - '0');
    }
    int j = 10;
    for(char i = 'A'; i <= 'F'; i++)
    {
        hexaMap[i] = j;
        j++;
    }

    cin >> j;
    string hudai;
    getline(cin, hudai);
    while(j--)
    {
        string a, b;
        char ch;
        cin >> a >> ch >> b;
        int result;
        int numA = hexaIntoDecimal(a);
        int numB = hexaIntoDecimal(b);
        if(ch == '+'){
            result = numA + numB;
        }
        else result = numA - numB;


        cout << decimalIntoBinary(numA) << " " << ch << " " << decimalIntoBinary(numB) << " = " << result << endl;
    }

    return 0;
}
