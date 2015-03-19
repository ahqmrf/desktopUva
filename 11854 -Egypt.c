#include<stdio.h>
#include<math.h>

int main()
{
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c) == 3 && (a && (b && c)))
    {
        if(a*a == b*b+c*c || b*b == c*c+a*a || c*c == a*a + b*b) printf("right\n");
        else printf("wrong\n");
    }

    return 0;
}
