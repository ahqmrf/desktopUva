#include <bits/stdc++.h>
using namespace std;

const int MX = 6000100;
char in[MX];
int n, m, len[MX], deq[MX];
int which[MX], sa[MX], lcp[MX], b[MX];
void buildLCP(char *t, int n, int *a, int *lcp) {
    int h = 0;
    rep(i, n+1) b[a[i]] = i;
    rep(i, n+1) {
        if (b[i]){
            for (int j = a[b[i]-1]; j+h<n && i+h<n && t[j+h] == t[i+h]; ++h);
            lcp[b[i]] = h;
        } else lcp[b[i]] = -1;
        if (h > 0) --h;
    }
}

int main(){
    int cs; scanf("%d", &cs);
    while(cs--){
        scanf("%d", &n);
        m = 0;
        rep(i,n){
            scanf("%s", in+m);
            len[i] = strlen(in+m);
            m += len[i];
            in[m++] = '0' + i;
            len[i] = m;
        }
        len[m] = 0;
        SA_IS((unsigned char*)in, sa, m+1, 256, sizeof(char));
        buildLCP(in, m, sa, lcp);
        
        int cur = 0;
        rep(i,m+1){
            if(i == len[cur] - 1) which[b[i]] = n, cur++;
            else which[b[i]] = cur;
        }
        
        int ans = 0, k = 0, use[6] = {}, h = 0, t = 0;
        for(int l = 0, r = 0; l < m; l++){
            while(l > r) r++;
            while(r <= m && k < n){
                int idx = which[r];
                if(idx < n && use[idx]++ == 0) k++;
                while(h < t && lcp[deq[t-1]] >= lcp[r]) t--;
                if(r) deq[t++] = r;
                r++;
            }
            if(k < n) break;
            ans = max(ans, lcp[deq[h]]);
            
            if(h < t && deq[h] <= l+1) h++;
            int idx = which[l];
            if(idx < n && --use[idx] == 0) k--;
        }
        printf("%d\n", ans);
    }
    return 0;
}