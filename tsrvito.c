#include <stdio.h>
#include <string.h>

int main()
{
    int testCase;
    scanf("%d",&testCase);
    while(testCase--)
    {
        int k;
        scanf("%d",&k);
        getchar();

        int i=0,j,m,characterRate[k];
        char character[k],temp;

        for(i=0;i<k;i++)
        {
            scanf("%c %d",&character[i],&characterRate[i]);
            getchar();
        }

        int M;
        scanf("%d",&M);

        char article[10000];

        getchar();

        double payment=0;

        for(i=0;i<M;i++)
        {
            gets(article);
            for(j=0;j<strlen(article);j++)
            {
                temp=article[j];

                for(m=0;m<k;m++)
                {
                    if(temp==character[m])
                    {
                        payment=payment+characterRate[m];
                        break;
                    }
                }
            }
        }






        payment=payment/100;

        printf("%.2lf$\n",payment);

    }
    return 0;
}
