#include<stdio.h>

int main (void)
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        char input[10];
        int num, diff;
        int charNum;
        scanf("%s", input);
        num = (input[4]-'0')*1000 + (input[5]-'0')* 100 + (input[6]-'0')*10 + input[7]-'0';
        charNum = (input[0]-65)*676 + (input[1]-65)*26 + (input[2]-65);
        diff = charNum - num;
        if(diff > 100 || diff < - 100) printf("not nice\n");
        else printf("nice\n");
    }
    return 0;
}
