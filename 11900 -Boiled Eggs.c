#include <stdio.h>
int main (void)
{
    int test, count, weight, tolerate, i=1, eggW, eggN, sum;
    scanf("%d", &test);
    while(test-- && (3 == scanf("%d%d%d",&eggN, &tolerate, &weight))){
        count = 0;
        sum = 0;
        while(eggN--){
            scanf("%d",&eggW);
            sum = sum + eggW;
            if(sum<=weight && count<=tolerate-1) count++;
        }

        printf("Case %d: %d\n", i++, count);
    }

    return 0;
}
