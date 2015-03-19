#include <stdio.h>
int main (void)
{
    int decimal;
    while(1==scanf("%d",&decimal) && decimal != 0){
        int count = 0;
        int n = decimal;
        while(decimal!=0){
            if(decimal%2==1) count++;
            decimal = decimal/2;
        }
        if(count%2==0) printf("The parity of is even\n");
        else printf("odd\n");
        i++;
    }
    return 0;
}
