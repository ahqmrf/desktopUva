#include<stdio.h>
#include<string.h>

main()
{
    int cases, i, n, c = 1, size;
    char line[1000];
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &n);
        getchar();
        if(c>1) printf("\n");
        printf("Case %d:\n", c++);
        while(n--)
        {
            gets(line);
            size = strlen(line);
            line[size] = '$';
            for(i=0; i<size; i++)
                if(!(line[i] == ' ' && line[i+1] == ' '))
                    printf("%c", line[i]);
            printf("\n");
        }
    }
}
