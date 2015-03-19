#include<bits/stdc++.h>
#define int64 long long int

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
        stringstream ss;;
        ss << hateAche;
        string hateAcheString;
        ss >> hateAcheString;
        result = hateAcheString + result;
    }

    return result;
}

string multiply(string str, char ch)
{
    if(ch == '0') return "0";
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

vector<string> MultiplyEvolution(string a, string b, vector<string> &terms)
{
    int n = 0;
    vector<string> BigInteger;
    for(int i = b.length()-1; i >= 0; i--)
    {
        string mul = multiply(a, b[i]);
        terms.push_back(mul);
        for(int j = 0; j < n; j++)
        {
            char ch = '0';
            mul += ch;
        }
        n++;
        BigInteger.push_back(mul);

    }

    return BigInteger;

}

int main (void)
{
    int64 multiplicand, multiplier;
    while(cin >> multiplicand)
    {
        if(multiplicand == 0){
            break;
        }
        cin >> multiplier;
        string a, b;
        stringstream ss, sss;
        ss << multiplicand;
        ss >> a;
        sss << multiplier;
        sss >> b;
        if(b == "0")
        {
            cout << a << endl;
            int m = a.length();
            for(int i=0; i<m-1; i++) cout << " ";
            cout << 0 << endl;
            for(int i=0; i<m; i++) cout << "-";
            cout << endl;
            for(int i=0; i<m-1; i++) cout << " ";
            cout << 0 << endl;
            continue;
        }
        vector<string> terms;
        vector<string> BigInteger = MultiplyEvolution(a, b, terms);
        string ans = removeLeadingZero(add(BigInteger));
        int len;
        if(ans != "0")len = ans.length();
        else len = a.length();
        for(int i=0; i<len-a.length(); i++) cout << " ";
        cout << a << endl;
        for(int i=0; i<len-b.length(); i++) cout << " ";
        cout << b << endl;
        if(terms.size() > 1){
        int l1 =  terms[0].length();
        int l2 =  a.length();
        if(l2 > l1) l1 = l2;
        for(int i=0; i<len-l1; i++) cout << " ";
        for(int i=0; i<l1; i++) cout << "-";
        cout << endl;
        int n = 0;

        for(int i = 0; i<terms.size(); i++)
        {
            l1 = terms[i].length();
            for(int j=0; j<len-l1-n; j++)cout << " ";
            cout << terms[i] << endl;
            n++;
        }
        }
        int l1 = ans.length();
        for(int i = 0; i<len-l1; i++) cout <<" ";
        for(int i = 0; i<len; i++) cout << "-";
        cout << endl;

        for(int i = 0; i<len-l1; i++) cout << " ";
        cout << ans << endl;

    }
    return 0;
}
