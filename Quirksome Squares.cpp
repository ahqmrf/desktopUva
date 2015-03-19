#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int main (void)
{
    vector<string> two, four, six, eight;
    two.push_back("00");
    two.push_back("01");
    four.push_back("0000");
    four.push_back("0001");
    six.push_back("000000");
    six.push_back("000001");
    eight.push_back("00000000");
    eight.push_back("00000001");





    int l2 = two.size();
    int l4 = four.size();
    int l6 = six.size();
    int l8 = eight.size();

    int n;
    while(cin >> n)
    {
        if(n == 2){
            for(int i = 10; i <= 99; i++)
            {
                stringstream ss;
                string s;
                int v = i/10;
                int r = i % 10;
                if((v+r)*(v+r) == i)
                {
                    ss << i;
                    ss >> s;
                    two.push_back(s);
                }
            }
            for(int i = 0; i < two.size(); i++){
                cout << two[i] << endl;
            }
        }
        else if(n == 4){
            for(int i = 100; i <= 9999; i++)
            {
                stringstream ss;
                string s;
                int v = i/100;
                int r = i % 100;
                if((v+r)*(v+r) == i)
                {
                    ss << i;
                    ss >> s;
                    if(i < 1000) s = '0' + s;
                    four.push_back(s);
                }
            }

            for(int i = 0; i < four.size(); i++)
                cout << four[i] << endl;
        }
        else if(n == 6){
                for(int i = 10000; i <= 999999; i++)
    {
        stringstream ss;
        string s;
        int v = i/1000;
        int r = i % 1000;
        if((v+r)*(v+r) == i)
        {
            ss << i;
            ss >> s;
            if(i < 100000) s = '0' + s;
            six.push_back(s);
        }
    }

            for(int i = 0; i < six.size(); i++)
                cout << six[i] << endl;}
        else if(n == 8){
                    for(int i = 1000000; i <= 99999999; i++)
    {
        stringstream ss;
        string s;
        int v = i/10000;
        int r = i % 10000;
        if((v+r)*(v+r) == i)
        {
            ss << i;
            ss >> s;
            if(i < 10000000) s = '0' + s;
            eight.push_back(s);
        }
    }

            for(int i = 0; i < eight.size(); i++)
                cout << eight[i] << endl;}
    }

    return 0;

}
