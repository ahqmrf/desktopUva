#include <stdio.h>
#include <string.h>

int main()
{
    int countNumber=0;
    for(;;)
    {
        countNumber++;

        char puzzle[5][8],movement,temp;
        int i,j,count=0,spaceI,spaceJ;

        for(i=0;i<5;i++)
        {
            gets(puzzle[i]);
            if(!strcmp(puzzle[i], "Z")) return 0;
        }

        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(puzzle[i][j]==' ')
                {
                    spaceI=i;
                    spaceJ=j;
                    break;
                }
            }
        }

        while(scanf("%c",&movement))
        {
            if(movement=='0')
            break;


            if(movement=='A')
            {
                puzzle[spaceI][spaceJ]=puzzle[spaceI-1][spaceJ];
                puzzle[spaceI-1][spaceJ]=' ';
                spaceI=spaceI-1;
            }

            else if(movement=='B')
            {
                puzzle[spaceI][spaceJ]=puzzle[spaceI+1][spaceJ];
                puzzle[spaceI+1][spaceJ]=' ';
                spaceI=spaceI+1;
            }

            else if(movement=='R')
            {
                puzzle[spaceI][spaceJ]=puzzle[spaceI][spaceJ+1];
                puzzle[spaceI][spaceJ+1]=' ';
                spaceJ=spaceJ+1;
            }

            else if(movement=='L')
            {
                puzzle[spaceI][spaceJ]=puzzle[spaceI][spaceJ-1];
                puzzle[spaceI][spaceJ-1]=' ';
                spaceJ=spaceJ-1;
            }

            if(spaceI <0 || spaceI>4 || spaceJ<0 || spaceJ>4)
            {count=1;
            break;}

        }

        if(countNumber > 1) printf("\n");

        if(count==0)
        {
            printf("Puzzle #%d:\n",countNumber);
            for(i=0;i<5;i++)
            {
                for(j=0;j<4;j++)
                {
                    printf("%c ",puzzle[i][j]);
                }
                printf("%c\n", puzzle[i][4]);
            }
        }

        else
        printf("Puzzle #%d:\nThis puzzle has no final configuration.\n",countNumber);
        getchar();

    }

    return 0;
}

