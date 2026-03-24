#include "sort_array.h"

static void heaping(int arr[], int n, int i){
    int max = i;
    int l = 2 * i + 1; //left child
    int r = 2 * i + 2; // right child

    if(l < n && arr[l] > arr[max])
        max = l;
    
    if(r < n && arr[r] > arr[max])
        max = r;
    
    if(max != i){
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;

        heaping(arr, n, max);
    }
}

void heap_sort(int arr[], int n){
    for(int i = n / 2 - 1; i >= 0; i--)
        heaping(arr, n, i);

    for(int i = n - 1; i >= 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
    
        heaping(arr, i, 0);
    }
}

