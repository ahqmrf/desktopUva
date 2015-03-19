#include<stdio.h>
#include<string.h>

int main (void)
{
    char ch[10];
    int no = 1;
    while(scanf("%s", ch) && strcmp(ch, "*"))
    {
        if(!strcmp(ch, "Umrah")) printf("Case %d: Hajj-e-Asghar\n", no++);
        else printf("Case %d: Hajj-e-Akbar\n", no++);
    }
    return 0;
}
