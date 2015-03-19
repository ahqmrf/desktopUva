#include<stdio.h>
#include<string.h>

int main ()
{
    char word[][20] = {"HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE"};
    char language[][20] = {"ENGLISH", "SPANISH", "GERMAN", "FRENCH", "ITALIAN", "RUSSIAN"};

    char inp[20];
    int c = 1, i, f;
    while(scanf("%s", inp))
    {
        if(inp[0] == '#') break;
        f = 1;
        for(i=0; i<6; i++)
        {
            if(!strcmp(inp, word[i]))
            {
                printf("Case %d: %s\n", c++, language[i]);
                f = 0;
                break;
            }
        }
        if(f) printf("Case %d: UNKNOWN\n", c++);
    }
    return 0;
}
