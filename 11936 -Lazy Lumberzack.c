#include<stdio.h>

int main(void)
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a >= b+c || b >= a+c || c >= a+b) printf("Wrong!!\n");
        else printf("OK\n");
    }
    return 0;
}
