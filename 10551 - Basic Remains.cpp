#include<bits/stdc++.h>

using namespace std;

long long int to_decimal(string num, int base)
{

    long long int decimal = 0, multiplier;
    int power = 0;

    for(int i = num.length()-1; i >= 0; --i)
    {
        multiplier = (long long int)pow((double)base, (double)power);
        int n;
        switch(num[i])
        {
            case 'a':
			case 'A': n = 10; break;
			case 'b':
			case 'B': n = 11; break;
			case 'c':
			case 'C': n = 12; break;
			case 'd':
			case 'D': n = 13; break;
			case 'e':
			case 'E': n = 14; break;
			case 'f':
			case 'F': n = 15; break;
			default: n = num[i]-48;
        }
        decimal += n * multiplier;
        power++;
    }
    return decimal;
}

string to_any_base(long long int num, int base)
{
    string BaseB;
    string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while(num)
    {
        char ch = str[(num%base)];
        BaseB = ch + BaseB;
        num/=base;
    }
    return BaseB;
}

int main (void)
{
    int base;
    string num, mod;
    while(cin >> base && base)
    {
        cin >> num >> mod;
        if(num == mod)
        {
            cout << 0 << endl;
            continue;
        }
        long long int modInt;
        modInt = to_decimal(mod, base);
        if(modInt == 1)
        {
            cout << 0 << endl;
            continue;
        }
        long long int ans = 0;
        int len = num.length();

        for(int i = 0; i < len; i++)
        {
            ans *= base;
            int n;
            switch(num[i])
            {
                case 'a':
                case 'A': n = 10; break;
                case 'b':
                case 'B': n = 11; break;
                case 'c':
                case 'C': n = 12; break;
                case 'd':
                case 'D': n = 13; break;
                case 'e':
                case 'E': n = 14; break;
                case 'f':
                case 'F': n = 15; break;
                default: n = num[i]-48;
            }
            ans += n;
            ans %= modInt;
        }

        cout << to_any_base(ans, base) << endl;
    }
    return 0;
}
