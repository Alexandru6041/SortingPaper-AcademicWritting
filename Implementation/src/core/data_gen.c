#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_gen.h"
#include "variables.h"

const char *get_array_type_name(Type array_type) {
    switch (array_type) {
        case RANDOM: 
            return "Random";
        case SORTED: 
            return "Sorted";
        case REVERSED: 
            return "Reversed";
        case ALMOST_SORTED: 
            return "Almost Sorted";
        case MIXED: 
            return "Mixed";
        case FLAT: 
            return "Flat";

        default:
            return COLOR_RED "Provide an array type\n" NORMAL_COLOR "\n";

    }
}

int* generate_random_int_array(int size, Type Array_type) {
    int* arr = (int*) malloc(size * sizeof(int));

    if(arr == NULL) {
        printf(COLOR_RED "Could not allocate memory\n" NORMAL_COLOR);
        free(arr);
        return NULL;
    }
    
    for(int i = 0; i < size; i++){
        switch(Array_type){
            case RANDOM:
                arr[i] = rand();
                break;
            
            case SORTED:
            case ALMOST_SORTED:
                arr[i] = i * 5;
                break;
            
            case REVERSED:
                arr[i] = (size - i) * 5;
                break;
            
            case MIXED:
                arr[i] = (i < size / 2) ? (i * 5) : rand();
                break;
            
            case FLAT:
                arr[i] = rand() % 5;
                break;
            
            default:
                printf(COLOR_RED "Provide an array type\n" NORMAL_COLOR "\n");

        }
    }

        if(Array_type == ALMOST_SORTED) {
            ///10% of the elements in the array
            int swaps = size * (10.00 / 100);
            for(int i = 0; i < swaps; i++){
                int index1 = rand() % size;
                int index2 = rand() % size;
                int temp = arr[index1];

                arr[index1] = arr[index2];
                arr[index2] = temp;
            }
        }

    
    return arr;
}

int* copy_int_array(int* source, int size) {
    int* copy = (int*) malloc(size * sizeof(int));
    if (copy == NULL) {
        printf(COLOR_RED "Could not allocate memory\n" NORMAL_COLOR "\n");
        return NULL;
    }
    
    memcpy(copy, source, size * sizeof(int));
    
    return copy;
}

void print_int_array(int* arr, int size) {
    printf("[");

    int limit = (size < 10) ? size : 10; 
    for (int i = 0; i < limit; i++) {
        printf("%d ", arr[i]);
    }
    if (size > 10) {
        printf("... (+ %d numbers)", size - 10);
    }
    printf("]\n");
}