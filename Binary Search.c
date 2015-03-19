#include<stdio.h>
int BinarySearch(int array[], int n, int item)
{
    int i, first, last, middle;
    first = 0;
    last = n - 1;
    middle = (first + last) / 2;
    while( first <= last )
    {
        if(array[middle] < item) first = middle + 1;
        else if(array[middle] == item) return middle;
        else last = middle - 1;

        middle = (first + last) / 2;
    }

    if(first > last) return -1;
}
