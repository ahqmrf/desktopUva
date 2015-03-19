#include<algorithm>
#include<cstdio>

using namespace std;

int main (void)
{
    int a[10], t[10];
    int cases;
    scanf("%d", &cases);
    printf("Lumberjacks:\n");
    while(cases--)
    {
        for(int i=0; i<10; i++)
        {
            scanf("%d", &a[i]);
            t[i] = a[i];
        }
        sort(t, t+10);
        bool s = true;
        for(int i = 0; i<10; i++)
        {
            if(a[i] != t[i])
            {
                s = false;
                break;
            }
        }

        if(!s)
        {
            s = true;
            for(int i = 0, j = 9; i<10; i++, j--)
            {
                if(a[i] != t[j])
                {
                    s = false;
                    break;
                }
            }
            if(s) printf("Ordered\n");
            else printf("Unordered\n");
        }
        else printf("Ordered\n");
    }
    return 0;
}
