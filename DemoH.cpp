#include <iostream>
#include <cstdio>

using namespace std;

void merge(int ModArray[], int array[], int size, int start, int middle, int end)
{
    int *tempArray = new int[size];
    int *tempModArray = new int[size];
    for(int i = 0; i<size; ++i)
    {
        tempArray[i] = array[i];
        tempModArray[i] = ModArray[i];
    }

    int i = start;
    int j = middle + 1;
    int k = start;

    while(i <= middle && j <= end)
    {
        if(tempModArray[i] < tempModArray[j])
        {
            array[k] = tempArray[i];
            ModArray[k] = tempModArray[i];
            ++i;
        }

        else if(tempModArray[i] == tempModArray[j])
        {
            if(tempArray[i] < tempArray[j]){
            array[k] = tempArray[i];
            ModArray[k] = tempModArray[i];
            ++i;
            }
        }
        else
        {
            array[k] = tempArray[j];
            ModArray[k] = tempModArray[j];
            ++j;
        }
        ++k;
    }

    while(i <= middle)
    {
        array[k] = tempArray[i];
        ModArray[k] = tempModArray[i];
        ++i;
        ++k;
    }
    while(j <= end)
    {
        array[k] = tempArray[j];
        ModArray[k] = tempModArray[j];
        ++j;
        ++k;
    }
    delete [] tempArray;
    delete [] tempModArray;
}

void mergeSort(int ModArray[], int array[], int size, int start, int end)
{
    if(start<end)
    {
        int middle = (start + end) / 2;
        mergeSort(ModArray, array, size, start, middle);
        mergeSort(ModArray, array, size, middle + 1, end);
        merge(ModArray, array, size, start, middle, end);
    }
}

int main (void)
{
    int size, M;
    scanf("%d%d", &size, &M);
    int *array = new int [size];
    int *ModArray = new int [size];
    for(int i = 0; i<size; ++i)
    {
        scanf("%d", &array[i]);
        ModArray[i] = array[i] % M;
    }

    mergeSort(ModArray, array, size, 0, size-1);

    for(int i = 0; i<size; ++i)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}

