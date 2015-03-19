#include<stdio.h>
int main (void)
{
    char ch;
    while(scanf("%c", &ch) != EOF)
    {
        getchar();
        if(ch <= '8') printf("%c\n", ch+1);
        else if(ch == '9') printf("10\n");
        else if(ch >= 'A' && ch <= 'Z')
        {
            int n = ch - 54;
            printf("%d\n", n);
        }
        else
        {
            int n = ch - 59;
            printf("%d\n", n);
        }
    }
    return 0;
}
