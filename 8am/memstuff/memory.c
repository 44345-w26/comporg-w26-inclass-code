#include <stdlib.h>
#include <stdio.h>

int main()
{
    puts("Hello world!");
    int arr1[4]; // arr1: .skip 16
    float arr2[] = {3.14, .12, .23, 1.987};
    printf("sizeof int: %d\n", sizeof(int));
    return 0;
}