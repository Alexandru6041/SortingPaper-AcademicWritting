#include "sort_array.h"

void bubble_sort(int* arr, int size) {

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int aux = arr[j];
                
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }

}

void insertion_sort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i], j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int *arr, int size){
    for(int i = 0; i < size - 1; i++){
        int min = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[min])
                min = j;
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}