#include<math.h>
#include<stdio.h>

int NSteps(int difference)
{
    if(difference == 0) return 0;
    int steps = sqrt(difference);
    if(steps * steps == difference) steps = steps * 2 - 1;
    else if(steps * steps + steps < difference) steps = steps * 2 + 1;
    else steps = steps * 2;
    return steps;
}

main ()
{
    int x, y, cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d%d", &x, &y);
        printf("%d\n", NSteps(y-x));

    }
}
