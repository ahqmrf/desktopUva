#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {

        int weight, value;
} item_t;


#define n_items (sizeof(item)/sizeof(item_t))

typedef struct {
        uint32_t bits; /* 32 bits, can solve up to 32 items */
        int value;
} solution;


void optimal(item_t *item, int weight, int idx, solution *s)
{
        solution v1, v2;
        if (idx < 0) {
                s->bits = s->value = 0;
                return;
        }

        if (weight < item[idx].weight) {
                optimal(item, weight, idx - 1, s);
                return;
         }

        optimal(item, weight, idx - 1, &v1);
        optimal(item, weight - item[idx].weight, idx - 1, &v2);

        v2.value += item[idx].value;
        v2.bits |= (1 << idx);

        *s = (v1.value >= v2.value) ? v1 : v2;
}

int main(void)
{
        int k, N, i;
        while(scanf("%d%d", &N, &k)!=EOF)
        {

            item_t item[k];
            for(i = 0; i<k; i++)
            {
                scanf("%d", &item[i].value);
                item[i].weight = item[i].value;
            }
            int i = 0, w = 0;
            solution s = {0, 0};
            optimal(item, N, n_items - 1, &s);

            for (i = 0; i < n_items; i++) {
                    if (s.bits & (1 << i)) {
                            printf("%d ", item[i].weight);
                            w += item[i].weight;
                    }
            }
            printf("sum:%d\n", w);
        }
        return 0;
}
