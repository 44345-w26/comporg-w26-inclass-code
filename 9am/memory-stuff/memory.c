#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int arr1[4]; // arr1: .skip 16
    float arr2[] = {3.14, .12, .23, 1.0642};
    int allzeros[10] = {};
    int * dyn_arr;
    dyn_arr = malloc(10 * sizeof(int));
    dyn_arr[0] = 5;
    int * temp = dyn_arr;
    dyn_arr = malloc(20 * sizeof(int));
    // copy data from temp to dyn_arr
    //...
    free(temp);
    free(dyn_arr);

    // cache demo
    int matsize = 10000;
    int iters = 100;
    int ** matrix;
    matrix = malloc(matsize * sizeof(int*));
    for (int i=0; i<matsize; i++)
        matrix[i] = malloc(matsize * sizeof(int));

    clock_t start = clock();
    for (int iter = 0; iter < iters; iter ++)
    {
        for (int i=0; i<matsize; i++)
            for (int j=0; j<matsize; j++)
                matrix[i][j] = i;
    }
    clock_t end = clock();
    printf("Time for [i][j]: %f\n", (float)(end-start)/CLOCKS_PER_SEC);

    start = clock();
    for (int iter = 0; iter < iters; iter ++)
    {
        for (int i=0; i<matsize; i++)
            for (int j=0; j<matsize; j++)
                matrix[j][i] = i;
    }
    end = clock();
    printf("Time for [j][i]: %f\n", (float)(end-start)/CLOCKS_PER_SEC);

    for (int i=0; i<matsize; i++)
        free(matrix[i]);
    free(matrix);
    puts("Hello world!");
    return 0;
}