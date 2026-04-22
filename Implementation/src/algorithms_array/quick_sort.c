#include "sort_array.h"

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void quick_sort_recursive(int *arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        int pivot = arr[mid];

        int lt = low;   // Zona elementelor < pivot
        int i = low;    // Zona elementelor == pivot
        int gt = high;  // Zona elementelor > pivot

        while (i <= gt) {
            if (arr[i] < pivot) {
                swap(&arr[lt++], &arr[i++]);
            } else if (arr[i] > pivot) {
                swap(&arr[i], &arr[gt--]);
            } else {
                i++;
            }
        }

        quick_sort_recursive(arr, low, lt - 1);
        quick_sort_recursive(arr, gt + 1, high);
    }
}

void quick_sort(int *arr, int size) {
    if (size > 1) {
        quick_sort_recursive(arr, 0, size - 1);
    }
}