#include "sort_array.h"

static void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

/// moving all the numbers smaller than the pivot to the left and all the numbers greater than the pivot to the right
static int partition(int *arr, int low, int high){
    int mid = low + (high - low) / 2;
    swap(&arr[mid], &arr[high]);

    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

static void quick_sort_recursive(int *arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quick_sort_recursive(arr, low, pi - 1);
        quick_sort_recursive(arr, pi + 1, high);
    }

}

void quick_sort(int *arr, int size){
    if(size > 1){
        quick_sort_recursive(arr, 0, size - 1);
    }
}

