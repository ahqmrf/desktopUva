#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<map>


using namespace std;

int carry(int sum)
{
    return sum/10;
}

int digit(int sum)
{
    return sum%10;
}

string removeLeadingZero(string str)
{
    string a;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '0') str[i] = ' ';
        else break;
    }

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ');
        else a += str[i];
    }

    if(a.length() == 0) return "0";
    else return a;
}

string addSmall (string BigIntegerA, string BigIntegerB)
{
    int maxLength;
    if(BigIntegerA.length() >= BigIntegerB.length()) {
        maxLength = BigIntegerA.length();
        int l = BigIntegerB.length();
        for(int j = 0; j < maxLength-l; j++)
        {
            BigIntegerB = "0" + BigIntegerB;
        }
    }
    else {
        maxLength = BigIntegerB.length();
        int l = BigIntegerA.length();
        for(int j = 0; j < maxLength-l; j++)
        {
            BigIntegerA = "0" + BigIntegerA;
        }
    }


    int hateAche = 0;
    string result;
    for(int i = maxLength-1; i >= 0; i--)
    {
        int d = hateAche + (BigIntegerA[i] - '0') + (BigIntegerB[i] - '0');

        hateAche = carry(d);

        char ch = digit(d) + '0';
        result = ch + result;
    }

    if(hateAche > 0)
    {
        stringstream ss;
        ss << hateAche;
        string hateAcheString;
        ss >> hateAcheString;
        result = hateAcheString + result;
    }

    return removeLeadingZero(result);
}



string add (vector<string>BigInteger)
{
    int maxLength = 0;
    for(int i = 0; i < BigInteger.size(); i++)
    {
        if(BigInteger[i].length() >= maxLength) maxLength = BigInteger[i].length();
    }

    for(int i = 0; i < BigInteger.size(); i++)
    {
        int l = BigInteger[i].length();
        for(int j = 0; j < maxLength-l; j++)
        {
            BigInteger[i] = "0" + BigInteger[i];
        }

    }

    int hateAche = 0;
    string result;
    for(int i = maxLength-1; i >= 0; i--)
    {
        int sum = hateAche;
        for(int j = 0; j < BigInteger.size(); j++)
        {
            int d = BigInteger[j][i] - '0';
            sum += d;
        }

        hateAche = carry(sum);

        char ch = digit(sum) + '0';
        result = ch + result;
    }

    if(hateAche > 0)
    {
        stringstream ss;
        ss << hateAche;
        string hateAcheString;
        ss >> hateAcheString;
        result = hateAcheString + result;
    }

    return result;
}

string multiply(string str, char ch)
{
    int hateAche = 0;
    int mul = ch - '0';
    string result;
    for(int i = str.length()-1; i >= 0; i--)
    {
        int dig = str[i] - '0';
        dig = dig*mul + hateAche;
        ch = digit(dig) + '0';
        hateAche = carry(dig);
        result = ch + result;
    }

    if(hateAche > 0)
    {
        stringstream ss;
        ss << hateAche;
        string hateAcheString;
        ss >> hateAcheString;
        result = hateAcheString + result;
    }

    return result;
}

string MultiplyEvolution(string a, string b)
{
    int n = 0;
    vector<string> BigInteger;
    for(int i = b.length()-1; i >= 0; i--)
    {
        string mul = multiply(a, b[i]);
        for(int j = 0; j < n; j++)
        {
            char ch = '0';
            mul += ch;
        }
        n++;
        BigInteger.push_back(mul);

    }

    string res = add(BigInteger);

    return res;

}

string BigPow (string BigInt, int pw)
{
     if(BigInt == "0") return "0";
     if(pw == 0) return "1";

     string pro = BigInt;
     for(int i = 1; i < pw; i++)
     {
         pro = MultiplyEvolution(pro, BigInt);
     }
     pro = removeLeadingZero(pro);
     return pro;

}

int main (void)
{

    map<int, vector<string> > save;

    for(int aa = 0; aa<=15; aa++)
    {
        stringstream ss;
        string a;
        ss << aa;
        ss >> a;
        for(int b = 1; b<=150; b++)
        {
             save[aa].push_back(BigPow(a, b));
        }
    }

    int N;
    int a;
    cout << save[15][150] << endl;
    while(cin >> N >> a)
    {
        string sum = "0";
        for(int i = 1; i<=N; i++)
        {
            stringstream ss;
            string s;
            ss << i;
            ss >> s;
            sum = addSmall(sum, MultiplyEvolution(s, save[a][i]));
        }
        cout << sum << endl;
    }
    return 0;
}

