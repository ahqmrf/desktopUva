#include<iostream>
#include<string>

using namespace std;

int main()
{
    string in;
    char digit;
    while(cin >> digit >> in)
    {
        if(digit=='0' && in[0]=='0') return 0;
        int len = in.length();
        if(len == 1 && in[0] == digit) cout << 0 << endl;
        else if(len == 1 && in[0] != digit) cout << in << endl;
        else
        {
            string out, outF;
            for(int i=0; i<len; i++)
            {
                if(in[i] == digit) continue;
                out += in[i];
            }

            len = out.length();
            if(len == 0) cout << 0 << endl;
            else
            {
                bool found = false;
                for(int i=0; i<len; i++)
                {
                    if(out[i]!='0') found = true;
                    if(found) outF += out[i];
                }
                len = outF.length();
                if(len == 0) cout << 0 << endl;
                else cout << outF << endl;
            }


        }

    }
    return 0;
}
