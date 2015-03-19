#include<stdio.h>

int main()
{
    int a, b;
    char ch;
    while(scanf("%d", &a)!= EOF)
    {
        getchar();
        scanf("%c", &ch);
        scanf("%d", &b);
        if(ch == '/') printf("%d\n", a/b);
        else printf("%d\n", a%b);
    }
    return 0;
}
