#include <iostream>
#include <cstdio>

using namespace std;

void merge(int array[], int size, int start, int middle, int end)
{
    int *tempArray = new int[size];
    for(int i = 0; i<size; ++i)
    {
        tempArray[i] = array[i];
    }

    int i = start;
    int j = middle + 1;
    int k = start;

    while(i <= middle && j <= end)
    {
        if(tempArray[i] <= tempArray[j])
        {
            array[k] = tempArray[i];
            ++i;
        }
        else
        {
            array[k] = tempArray[j];
            ++j;
        }
        ++k;
    }

    while(i <= middle)
    {
        array[k] = tempArray[i];
        ++i;
        ++k;
    }
    while(j <= end)
    {
        array[k] = tempArray[j];
        ++j;
        ++k;
    }
    delete [] tempArray;
}

void mergeSort(int array[], int size, int start, int end)
{
    if(start<end)
    {
        int middle = (start + end) / 2;
        mergeSort(array, size, start, middle);
        mergeSort(array, size, middle + 1, end);
        merge(array, size, start, middle, end);
    }
}

int main (void)
{
    int size;
    scanf("%d", &size);
    int *array = new int [size];
    for(int i = 0; i<size; ++i)
    {
        scanf("%d", &array[i]);
    }

    mergeSort(array, size, 0, size-1);

    for(int i = 0; i<size; ++i)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}
