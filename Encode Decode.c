#include<stdio.h>
#include<string.h>

int main (void)
{
    char ascii[200], ch1, ch2;
    int i, j, k;
    ch1 = 'A';
    ch2 = 'a';
    for(i = 0; i < 26; i++)
    {
        ascii[ch1] = ch1;
        ascii[ch2] = ch2;
        ch1++;
        ch2++;
    }

    ascii[32] = ' ';
    ascii[33] = '!';
    ascii[44] = ',';
    ascii[46] = '.';
    ascii[58] = ':';
    ascii[59] = ';';
    ascii[63] = '?';

    char msg[100];
    while(gets(msg))
    {
        if(msg[0] >= 48 && msg[0] <= 57)
        {
            int l = strlen(msg);
            int i, j, k = 0;
            char ch[81];
            for(i = 0; i < l; )
            {
                int num;
                if(msg[i+1] >= '3')
                {
                    num =   (msg[i+1]-'0') * 10 + (msg[i]-'0');

                    i += 2;
                }

                else
                {
                    num = (msg[i+2]-'0')*100 + (msg[i+1]-'0')*10 + (msg[i]-'0');

                    i += 3;
                }

                ch[k] = ascii[num];
                k++;

            }


            for(i = k-1; i>= 0; i--)
            {
                printf("%c", ch[i]);
            }
            printf("\n");
        }

        else
        {
            int l = strlen(msg);
            for(i = l-1; i >=0; i--)
            {
                int num = msg[i];
                if(num < 100){
                    num = 10*(num%10) + num/10;
                }

                else{
                    int t = num;
                    num = (t%10)*100;
                    t /= 10;
                    num = num + 10*(t%10) + t/10;
                }
                printf("%d", num);
            }
            printf("\n");
        }
    }

    return 0;
}
