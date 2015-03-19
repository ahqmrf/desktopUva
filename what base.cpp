#include<string>
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

int to_decimal(string str, int base)
{
    int decimal = 0, k = str.length();
    double Base = base, xp = 0.0;
    for(int i=k-1; i>=0; i--)
    {
        int digit;
        if(str[i]<=90 && str[i]>=65)
        {
            digit = str[i]-55;
        }
        else digit = str[i]-'0';
        decimal += (int)pow(Base, xp)*digit;
        xp += 1.0;
    }
    return decimal;
}

string to_baseB(int num, int base)
{
    string bBased;
    while(num)
    {
        int digit = num%base;
        char charDigit;
        if(digit > 9) charDigit = 'A'+(digit-10);
        else charDigit = digit+'0';
        bBased = charDigit + bBased;
        num/=base;
    }
    return bBased;
}

int main (void)
{
    string A[36], B[36];

    int a=12, b=5;
    for(int i=2; i<36; i++)
    {
        A[i] = to_baseB(a, i);
        B[i] = to_baseB(b, i);
        cout << to_decimal(A[i], i) << " " << to_decimal(B[i], i) << endl;

    }
    bool flag = false;
    for(int i=2; i<36; i++)
    {
        for(int j=2; j<36; j++)
        {
            int sa = to_decimal(A[i], i);
            int sb = to_decimal(B[j], j);
         //   cout << sa << " " << sb << endl;
            if(sa==sb){
           //     cout << i << " " << j << endl;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    return 0;
}

