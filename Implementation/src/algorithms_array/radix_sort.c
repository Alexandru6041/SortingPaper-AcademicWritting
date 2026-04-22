#include "sort_array.h"
#include <stdlib.h>

static void counting_sort(int *arr, int size, int exp) {
    int *output = (int *)malloc(size * sizeof(int));
    int count[10] = {0};

    for(int i = 0; i < size; i++)
        count[(arr[i] / exp) % 10]++;

    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for(int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for(int i = 0; i < size; i++)
        arr[i] = output[i];

    free(output);
}

void radix_sort(int *arr, int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++)
        if(arr[i] > max)
            max = arr[i];

    for(int exp = 1; max / exp > 0; exp *= 10)
        counting_sort(arr, size, exp);
}


