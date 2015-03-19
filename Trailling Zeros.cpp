#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;


int main (void)
{
    double nod[105050];
    int i, j, k, c, p, N, B, noz;
    double ans=0;
    nod[0] = ans;
    for (i=1;i<=105000;i++)
    {
      ans+=log(i);
      nod[i] = ans;
    }
    while (scanf("%d%d",&N,&B)!=EOF)
    {
          noz=N;
          j=B;
          for (i=2;i<=B;i++)
          {
              if (j%i==0)
              {
                 p=0;
                 while (j%i==0)
                 {
                       p++;
                       j/=i;
                 }
                 c=0;
                 k=N;
                 while (k/i>0)
                 {
                       c+=k/i;
                       k/=i;
                 }
                 noz=min(noz,c/p);
              }
          }
          double ans=nod[N];
          ans/=log(B);ans+=1.0;
          ans=floor(ans);
          printf("%d %.0lf\n",noz,ans);
    }

    return 0;
}

