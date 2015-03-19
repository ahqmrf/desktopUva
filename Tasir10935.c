#include <stdio.h>

int main()
{
    int totalCard;
    scanf("%d",&totalCard);

    while(totalCard != 0 )
    {
        int i,cardArray[totalCard],discardedCard[totalCard-1],j=0;

        for(i=0;i<totalCard;i++)
        {
            cardArray[i]=i+1;
        }


        int k=0,m,n,x;

        for(i=0;i<totalCard-1;i++)
        {
            discardedCard[j]=cardArray[0];
            j++;

            //--------------swapping 2nd card

            int temp=cardArray[1];

            cardArray[0]=cardArray[2];
            for(m=1;m<totalCard-(k+1);m++)
            {
                cardArray[m]=cardArray[m+2];
            }
            cardArray[m]=temp;

            cardArray[totalCard-k-1]=discardedCard[j-1];

            k++;
            for(x=0;x<totalCard;x++)
                {
                    printf("%d\n",cardArray[x]);
                }
                printf("\n");

        }
        printf("Discarded cards: %d",discardedCard[0]);

        for(i=1;i<totalCard-1;i++)
        {
            printf(", %d",discardedCard[i]);
        }

        int addition=0,addition2=0;

        for(i=0;i<totalCard-1;i++)
        {
            addition2=addition2+discardedCard[i];
            addition=addition+cardArray[i];
        }
        addition=addition+cardArray[i];

        printf("\n");
        printf("Remaining card: %d\n",addition-addition2);

        scanf("%d",&totalCard);
    }
    return 0;
}

