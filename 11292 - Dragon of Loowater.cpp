#include<set>
#include<cstdio>

using namespace std;


int main (void)
{
    int m, n;
    while(scanf("%d%d", &n, &m), n||m)
    {
        multiset<int> st;
        multiset < int >::iterator it;
        int *head = new int[n], height;
        for(int i=0; i<n; i++) scanf("%d", &head[i]);
        for(int i=0; i<m; i++) scanf("%d", &height), st.insert(height);
        bool failed = false;
        int golds = 0;

        for(int i=0; i<n; i++)
        {
            if((it=st.lower_bound(head[i]))==st.end())
            {
                failed = true;
                break;
            }

            golds += *it;
            st.erase(it);
        }
        if(failed) printf("Loowater is doomed!\n");
        else printf("%d\n", golds);
    }
    return 0;
}
