#include<sstream>
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>

using namespace std;

int lengthOfNumber(int num)
{
    int count = 0;
    while(num > 0)
    {
        count++;
        num /= 10;
    }

    return count;
}
int reverseNumber (int num)
{
    int len = lengthOfNumber(num), reversedNumber = 0;
    int div = 10, mul;
    double pw = (double)(len - 1);
    pw = pow(10.0, pw);
    mul = pw;

    while(len--)
    {
         int rem = num % 10;
         reversedNumber += (rem * mul);
         num /= 10;
         mul /= 10;
    }

    return reversedNumber;
}


int main (void)
{
    string msg;
    while(getline(cin, msg))
    {
        int doirgho = msg.length();
        if(msg[0] <= 57 && msg[0] >= 48)
        {
            vector<char>ch;
            for(int i = 0; i < doirgho; i++)
            {
                if(msg[i+1] >= '3')
                {
                    int number = (msg[i+1]-'0') * 10 + (msg[i] - '0');
                    char c = number;
                    ch.push_back(c);
                    i++;
                }

                else
                {
                    int number = (msg[i+2] - '0') * 100 + (msg[i+1]-'0') * 10 + (msg[i] - '0');
                    char c = number;
                    ch.push_back(c);
                    i += 2;
                }
            }

            for(int i = ch.size()-1; i >=0; i--)
            {
                printf("%c", ch[i]);
            }
        }

        else
        {
            for(int i = doirgho-1; i >= 0; i--)
            {
                int ascii = msg[i];
                int rAscii = reverseNumber(ascii);
                printf("%d", rAscii);
            }
        }
        printf("\n");
    }
    return 0;
}
