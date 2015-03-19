#include<stdio.h>
#include<string.h>

int main (void)
{
    int len, k, i, j, found;
    char digit, input[1000];
    while(scanf("%c %s", &digit, input) == 2)
    {
        if(digit == '0' && input[0] == '0') break;
        len = strlen(input);
        if(digit == input[0] && len == 1) printf("0\n");
        else
        {
            char output[1000], output_final[1000];
            for(i = 0, k = 0; i < len; i++)
            {
                if(input[i] == digit) continue;
                output[k] = input[i];
                k++;
            }

            if(k == 0) printf("0\n");
            else
            {
                found = 0;
                for(i = 0, j = 0; i < k; i++)
                {
                    if(output[i] != '0')
                    {
                        found = 1;
                    }
                    if(found)
                    {
                        output_final[j] = output[i];
                        j++;
                    }
                }

                if(j == 0) printf("0\n");
                else printf("%s\n", output_final);
            }
        }
    }
    return 0;
}
