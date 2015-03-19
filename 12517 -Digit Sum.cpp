  #include <cstdio>
 typedef long long LL;
 LL dp(LL x){
      LL ret = 0;
      LL p[11];
      p[0] = 1;
      for(int i = 1;i <= 10;i++)
          p[i] = p[i-1]*10;
      int idx[11],cnt = 0;
     while(x){
         idx[cnt++] = x%10;
         x /= 10;
     }
     int sum = 0;
     for(int pos = cnt-1;pos >= 0;pos--){
         for(int j = 0;j < idx[pos];j++){
             ret += (sum+j) * p[pos];
             if(pos) ret += (p[pos-1]*pos*45);
         }
         sum += idx[pos];
     }
     ret += sum;
     return ret;
}
 
int main(){
    LL a,b;
    while(scanf("%lld%lld",&a,&b),a+b){
        printf("%lld\n",dp(b)-dp(a-1));
    }
}

