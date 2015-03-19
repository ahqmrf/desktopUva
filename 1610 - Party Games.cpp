#include<bits/stdc++.h>

using namespace std;

int main ()
{
    int N;
    while(cin >> N, N)
    {
        vector<string> names(N);
        string ans;
        for(int i=0; i<N; i++) cin >> names[i];
        sort(names.begin(), names.end());
        string a = names[N/2-1], b = names[N/2];
        int al = a.length(), bl = b.length();
        if(al < bl)
        {
            for(int i=0; i<al; i++)
            {
                if(a[i] == b[i] || i==al-1) ans += a[i];
                else
                {
                    ans += (a[i]+1);
                    break;
                }

            }
        }

        else
        {
            for(int i=0; i<bl; i++)
            {
                if(a[i]==b[i]) ans += a[i];
                else
                {
                    if(i==bl-1)
                    {
                        if(i==al-1)
                        {
                            ans += a[i];
                            break;
                        }
                        if(a[i]+1 != b[i])
                        {
                            ans += (a[i]+1);
                            break;
                        }
                        else
                        {
                            ans += a[i];
                            for(int j=i+1; j<al; j++)
                            {
                                if(j == al-1)
                                {
                                    ans += a[j];
                                    break;
                                }
                                else if(a[j] != 'Z')
                                {
                                    ans += (a[j]+1);
                                    break;
                                }
                                else
                                {
                                    ans += a[j];
                                }
                            }
                            break;
                        }
                    }
                    else
                    {
                        ans += (a[i]+1);
                        break;
                    }

                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
