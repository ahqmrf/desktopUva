#include<stdio.h>
#include<math.h>
int LD(int num)
{
    while(num > 1)
    {

        num/=10;
    }

    return num;
}

int count(int num)
{
    int c  = 0;
    while(num > 0)
    {
        c++;
        num /=10;
    }

    return c;
}

int main (void)
{
    int a, b, ans;
    while(scanf("%d%d", &a, &b) == 2)
    {
        if(b >= a) printf("%d\n", b);
        else
        {
            int ldA = LD(a);
            double m;
            int dA = count(a);
            int dB = count(b);
            if(dA == dB)
            {
                m = pow(10, dA);
                ans = (int) m + b;
            }

            if(dA > dB)
            {
                m = pow(10, dB);
                int n = (int)m;
                dA--;
                double x = pow(10, dA);
                int y = (int)x;


                ans = y * ldA + b;

                while(1)
                {
                    if(ans > a) {
                        printf("%d\n", ans);
                        break;
                    }

                    else ans += n;
                }
            }


        }
    }

    return 0;
}
