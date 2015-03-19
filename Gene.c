#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxL 6000050
struct SuffixArray {
    int sa[maxL], h[maxL], n;
    int w[maxL], ta[maxL], tb[maxL];
    char str[maxL];
    void sort(int *x, int *y, int m) {
        static int i;
        for(i = 0; i < m; i++)
            w[i] = 0;
        for(i = 0; i < n; i++)
            w[x[y[i]]]++;
        for(i = 1; i < m; i++)
            w[i] += w[i-1];
        for(i = n-1; i >= 0; i--)
            sa[--w[x[y[i]]]] = y[i];
    }
    bool cmp(int *r, int a, int b, int l) {
        if(r[a] == r[b]) {
            if(a+l >= n || b+l >= n)
                return false;
            return r[a+l] == r[b+l];
        }
        return false;
    }
    void build_h() {
        int i, j, k;
        for(i = 0; i < n; i++)  ta[sa[i]] = i;
        for(i = 0; i < n; i++) {
            if(ta[i] == 0) {
                h[ta[i]] = 0;
                continue;
            }
            if(i == 0 || h[ta[i-1]] <= 1)
                k = 0;
            else
                k = h[ta[i-1]]-1;
            while(str[sa[ta[i]-1]+k] == str[sa[ta[i]]+k])
                k++;
            h[ta[i]] = k;
        }
    }
    void build() {
        int i, k, m = 128, p;
        int *x = ta, *y = tb, *z;
        n = strlen(str);
        x[n] = 0;
        for(i = 0; i < n; i++)
            x[i] = str[i], y[i] = i;
        sort(x, y, m);
        for(k = 1, p = 1; p < n; k *= 2, m = p) {
            for(p = 0, i = n-k; i < n; i++)
                y[p++] = i;
            for(i = 0; i < n; i++) {
                if(sa[i] >= k) {
                    y[p++] = sa[i]-k;
                }
            }
            sort(x, y, m);
            z = x, x = y, y = z;
            for(i = 1, p = 1, x[sa[0]] = 0; i < n; i++)
                x[sa[i]] = cmp(y, sa[i-1], sa[i], k) ? p-1 : p++;
        }
    }
};
SuffixArray in;
int check(int n, int len[], int com) {
    static bool used[7];
    static int ut, i, j;
    memset(used, 0, sizeof(used));
    ut = 0;
    for(i = 0; i < in.n; i++) {
        if(in.h[i] >= com) {
            for(j = 0; j < n; j++) {
                if(len[j] >= in.sa[i-1]) {
                    if(used[j] == false) {
                        used[j] = true;
                        ut++;
                        if(ut == n)
                            return 1;
                    }
                    break;
                }
            }
            for(j = 0; j < n; j++) {
                if(len[j] >= in.sa[i]) {
                    if(used[j] == false) {
                        used[j] = true;
                        ut++;
                        if(ut == n)
                            return 1;
                    }
                    break;
                }
            }
        } else {
            memset(used, 0, sizeof(used));
            ut = 0;
        }
    }
    return 0;
}
void solve(int n) {
    int i, idx = 0, pre;
    int len[7];
    int l = 1, r = 1000000, m;
    for(i = 0; i < n; i++) {
        scanf("%s", in.str+idx);
        pre = idx;
        idx = strlen(in.str);
        r = r < idx-pre ? r : idx-pre;
        in.str[idx] = i+'0';
        len[i] = idx;
        idx = idx+1;
    }
    in.str[idx] = '\0';
    in.build();
    in.build_h();

    int ans = 0;
    while(l <= r) {
        m = (l+r)>>1;
        if(check(n, len, m) == 0) {
            r = m-1;
        } else {
            ans = m;
            l = m+1;
        }
    }
    printf("%d\n", ans);
}
int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        solve(n);
    }
    return 0;
}
