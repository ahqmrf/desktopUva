# include<stdio.h>
# include<stdlib.h>
#include<string.h>

unsigned min(unsigned , unsigned , unsigned , unsigned);


unsigned getNthUglyNo(unsigned n)
{
    unsigned *ugly =
             (unsigned *)(malloc (sizeof(unsigned)*n));
    unsigned i2 = 0, i3 = 0, i5 = 0, i7 = 0;
    unsigned i;
    unsigned next_multiple_of_2 = 2;
    unsigned next_multiple_of_3 = 3;
    unsigned next_multiple_of_5 = 5;
    unsigned next_multiple_of_7 = 7;
    unsigned next_ugly_no = 1;
    *(ugly+0) = 1;

    for(i=1; i<n; i++)
    {
       next_ugly_no = min(next_multiple_of_2,
                           next_multiple_of_3,
                           next_multiple_of_5,
                           next_multiple_of_7);
       *(ugly+i) = next_ugly_no;
       if(next_ugly_no == next_multiple_of_2)
       {
           i2 = i2+1;
           next_multiple_of_2 = *(ugly+i2)*2;
       }
       if(next_ugly_no == next_multiple_of_3)
       {
           i3 = i3+1;
           next_multiple_of_3 = *(ugly+i3)*3;
       }
       if(next_ugly_no == next_multiple_of_5)
       {
           i5 = i5+1;
           next_multiple_of_5 = *(ugly+i5)*5;
       }
       if(next_ugly_no == next_multiple_of_7)
       {
           i7 = i7+1;
           next_multiple_of_7 = *(ugly+i7)*7;
       }
    }
    return next_ugly_no;
}


unsigned min(unsigned a, unsigned b, unsigned c, unsigned d)
{
    if(a <=b && a <= c && a <= d) return a;
    else if(b <=a && b <= c && b <= d) return b;
    else if(c <=b && c <= d && c <= a) return c;
    else return d;
}


int main()
{
    int n;
    while(scanf("%d", &n) == 1){
        if(n == 0) return 0;
        unsigned no = getNthUglyNo(n);
        char ch[3];
        if(n%100 >= 10 && n%100 <= 19)strcpy(ch,"th");
        else if(n%10 == 1) strcpy(ch,"st");
        else if(n%10 == 2) strcpy(ch,"nd");
        else if(n%10 == 3) strcpy(ch,"rd");
        else strcpy(ch,"th");
        printf("The %d%s humble number is %d.\n", n,ch,  no);
    }
    return 0;
}

