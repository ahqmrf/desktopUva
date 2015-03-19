#include<cstring>
#include<cstdio>

using namespace std;

int main (void)
{
    char str[1000];
    int cases, pizza, ing[129], sl;
    scanf("%d\n", &cases);
    while(cases--)
    {
        gets(str);
        memset(ing, 0, sizeof(ing));
        sl = strlen(str);
        for(int i=0; i<sl; i++)
        {
            ing[str[i]]++;
        }

        pizza = ing['A']/3;
        pizza = min(pizza, ing['R']/2);
        pizza = min(pizza, ing['M']);
        pizza = min(pizza, ing['G']);
        pizza = min(pizza, ing['I']);
        pizza = min(pizza, ing['T']);

        printf("%d\n", pizza);
    }
    return 0;
}
