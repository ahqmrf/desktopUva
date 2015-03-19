int s = primes.size();
    int n, m, cases, c = 1;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d", &m, &n);
        printf("Case %d:\n", c++);
        if((m > n && p[m] == false) || n == 0)  printf("Impossible to divide\n");
        else if(m == n && p[m] == false) printf("1\n");
        else
        {
            int P;
            if(p[m] == false) P = m;
            else
            {
                for(int i = 0; i < s && m >= primes[i]; i++)
                {
                    if(m % primes[i] == 0){
                        P = primes[i];
                    }
                }
            }


            if(P > n)  printf("Impossible to divide\n");
            else if(P == n) printf("1\n");
            else
            {
                int cnt = 0;
                double M  = P, j;
                while(m%P == 0 && m > 0){
                    cnt++;
                    m/= P;
                }

                int t = 1111111, d = 0;
                for(j = 1.0; ; j+=1.0)
                {
                    if(t == 0) break;
                    t = (int) (n/pow(M, j));
                    d = d+ t;
                }
                if(cnt > 0) d/= cnt;
                printf("%d\n", d);
            }
        }
    }
