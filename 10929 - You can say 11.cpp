#include<iostream>
#include<string>

using namespace std;

int main (void)
{
    string num;
    int sumOdd, sumEven, n;
    while(cin >> num && num != "0")
    {
        sumOdd = 0;
        sumEven = 0;
        n = num.length();
        for(int i = 0; i < n; i += 2)
        {
            sumOdd += (num[i] - '0');
        }

        for(int i = 1; i < n; i += 2)
        {
            sumEven += (num[i] - '0');
        }

        if((sumOdd-sumEven) % 11 == 0)  cout << num << " is a multiple of 11." << endl;
        else cout << num << " is not a multiple of 11." << endl;

    }
    return 0;
}
