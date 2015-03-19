#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
    char  str[100010],ss[1010];

    int test,q,l2,i,j,iden;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%s",str);

        scanf("%d", &q);
        while(q--)
        {
            scanf("%s",ss);
            l2 = strlen(ss);
            iden = 0, i = 0;

            if(str[0]==ss[0])
            {
                for(j = 0; j < l2; j++)
                {
                    if(str[i] == ss[j])
                    {
                        i++;
                    }
                    else if(str[i]=='\0')
                    {
                        iden = 1;
                        break;
                    }
                    else if(str[i] != ss[j])
                    {
                        iden=1;
                        break;
                    }
                }

                if(iden == 0) puts("y");
                else puts("n");
            }
            else puts("n");
        }
    }
    return 0;
}

