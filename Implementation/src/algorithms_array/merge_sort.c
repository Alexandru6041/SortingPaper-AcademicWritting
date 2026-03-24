#include <stdlib.h>
#include "sort_array.h"

void merge(int* arr, int* temp, int left, int mid, int right) {
    int i = left; 
    int j = mid + 1;
    int k = left;   

    while(i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid) {
        temp[k++] = arr[i++];
    }

    while(j <= right) {
        temp[k++] = arr[j++];
    }

    for(i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void merge_sort_recursive(int* arr, int* temp, int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2; 

        merge_sort_recursive(arr, temp, left, mid);
        merge_sort_recursive(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

void merge_sort(int* arr, int size) {
    if(size < 2) 
        return;
    
    int* temp = (int*)malloc(size * sizeof(int));
    if (temp != NULL) {
        merge_sort_recursive(arr, temp, 0, size - 1);
        free(temp);
    }
}