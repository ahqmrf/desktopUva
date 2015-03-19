#include<bits/stdc++.h>
using namespace std;
struct property
{
    string name;
    int day;
    int month;
    int year;
} mini, maxi;


int main ()
{
    int N;
    mini.name = "";
    mini.day = 2147483647;
    mini.month = 2147483647;
    mini.year = 2147483647;

    maxi.name = "";
    maxi.day = 0;
    maxi.month = 0;
    maxi.year = 0;

    string nam;
    int day, month, year;
    cin >> N;
    while(N--)
    {
        cin >> nam >> day >> month >> year;
        if(year < mini.year)
        {
            mini.name = nam;
            mini.day = day;
            mini.month = month;
            mini.year = year;
        }
        else if(year == mini.year)
        {
            if(month < mini.month)
            {
                mini.name = nam;
                mini.day = day;
                mini.month = month;
                mini.year = year;
            }
            else if(month == mini.month)
            {
                if(day < mini.day)
                {
                    mini.name = nam;
                    mini.day = day;
                    mini.month = month;
                    mini.year = year;
                }
            }
        }

        if(year > maxi.year)
        {
            maxi.name = nam;
            maxi.day = day;
            maxi.month = month;
            maxi.year = year;
        }
        else if(year == maxi.year)
        {
            if(month > maxi.month)
            {
                maxi.name = nam;
                maxi.day = day;
                maxi.month = month;
                maxi.year = year;
            }
            else if(month == maxi.month)
            {
                if(day > maxi.day)
                {
                    maxi.name = nam;
                    maxi.day = day;
                    maxi.month = month;
                    maxi.year = year;
                }
            }
        }

    }

    cout << maxi.name << endl;
    cout << mini.name << endl;

    return 0;
}
