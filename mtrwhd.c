#include <stdio.h>
int convert(char c) {
    if (c>='A' && c<= 'C') return 2;
    else if ( c>='D' && c<='F' ) return 3;
    else if ( c>='G' && c<='I' ) return 4;
    else if ( c>='J' && c<='L' ) return 5;
    else if ( c>='M' && c<='O' ) return 6;
    else if ( c>='P' && c<='S' ) return 7;
    else if ( c>='T' && c<='V' ) return 8;
    else if ( c>='W' && c<='Z' ) return 9;
    else return 0;
}
int main() {
    char code[49];
    while (scanf("%s",code)==1) {
        int len = strlen(code);
        int i;
        for (i=0;i<len;i++) {
            int k = convert(code[i]);
            if (k!=0) printf("%d",k);
            else printf("%s",code[i]);
        }
        printf("\n");
    }

    return 0;

    }

