#include<bits/stdc++.h>

#define maxN 262500

using namespace std;

struct entry
{
    int first, second, p;
    bool operator <(const entry &b) const
    {
        if(first==b.first) return second<b.second;
        else return first<b.first;
    }
} L[maxN];

char text[maxN], pattern[1010];
int textLength, patternLength;
int P[20][maxN], stop;

void suffix_array()
{
    stop = 0;

    for (int i = 0; i < textLength; i ++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z') P[0][i] = text[i]-'A';
        else P[0][i] = text[i] - 'a'+26;
    }

    stop = 1;

    for (int cnt = 1; cnt >> 1 < textLength; stop++, cnt <<= 1)
    {
        for (int i = 0; i < textLength; i ++)
        {
            L[i].first = P[stop - 1][i];
            if(i + cnt < textLength) L[i].second =  P[stop - 1][i + cnt];
            else L[i].second =  -1;
            L[i].p = i;
        }

        sort(L, L+textLength);

        for (int i = 0; i < textLength; i ++)
        {
            if(i > 0 && L[i].first == L[i - 1].first && L[i].second == L[i - 1].second)
                P[stop][L[i].p] = P[stop][L[i - 1].p];
            else P[stop][L[i].p] = i;
        }
    }
}

int is_substring(int mid)
{
    for(int i=L[mid].p, j=0; i<textLength && j<patternLength; i++,j++)
    {
        if((j == patternLength-1) && (text[i]==pattern[j])) return 0;
        else if(text[i]<pattern[j]) return -1;
        else if(text[i]>pattern[j]) return 1;
    }
    return -1;
}

int main()
{
    int t,q,ret,low,high,mid;

    bool check;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(text);
        textLength = strlen(text);

        suffix_array();

        scanf("%d",&q);
        getchar();

        while(q--)
        {
            gets(pattern);
            patternLength = strlen(pattern);

            low = 0;
            high = textLength-1;
            check = false;

            while(low <= high)
            {
                mid = (low+high)/2;
                ret = is_substring(mid);
                if(ret == 0)
                {
                    check = true;
                    break;
                }
                else if(ret<0) low = mid+1;
                else high = mid-1;
            }

            if(check) printf("y\n");
            else printf("n\n");
        }
    }

    return 0;
}


