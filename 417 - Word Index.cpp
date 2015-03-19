#include<cstdio>
#include<string>
#include<queue>
#include<iostream>

using namespace std;

int main (void)
{
    string str;
    while(cin>>str)
    {
        bool valid = true;
        for(int i = 1; i<str.length(); i++)
        {
            if(str[i] <= str[i-1])
            {
                valid = false;
                break;
            }
        }
        if(valid)
        {
            int counts = 0;
            queue<string>bfs;
            bfs.push("");
            while(true)
            {
                string v = bfs.front();
                if(str == v)
                {
                    break;
                }
                counts++;
                bfs.pop();

                if(v == "")
                {
                    for(char ch = 'a'; ch <= 'z'; ch++)
                    {
                        char s[2];
                        s[0] = ch;
                        s[1] = 0;
                        bfs.push(s);
                    }
                }
                else
                {
                    char last = v[v.length()-1];
                    for(char ch = last+1; ch <= 'z'; ch++)
                    {
                        bfs.push(v + ch);
                    }
                }

            }
            printf("%d\n", counts);
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
