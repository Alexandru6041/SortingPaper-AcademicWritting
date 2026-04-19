#include "variables.h"
#include "data_gen.h"
#include "list_utils.h"
#include <stdlib.h>
#include <stdio.h>



static clock_t start_timer() {
    return clock();
}

static double stop_timer(clock_t start_time) {
    clock_t end_time = clock();

    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

void run_array_benchmark(const char* algorithm_name, void (*sort_function)(int*, int), int *array, int size){
    printf("%-15s | ", algorithm_name);
    
    int iterations = 1;

    if(size <= 100) {
        iterations = 10000;
    } else if (size <= 1000) {
        iterations = 1000;
    } else if (size < 10000) {
        iterations = 100; 
    }

    clock_t start = start_timer();
    for(int i = 0; i < iterations; i++) {
        int* test_array = copy_int_array(array, size);
        
        sort_function(test_array, size);
        
        free(test_array);
    }
    

    double total_time = stop_timer(start);
    
    printf("%.6f seconds\n", total_time);
}

void run_list_benchmark(const char* algorithm_name, void (*sort_func)(Node**), Node* master_list, int size) {

    printf("%-15s | ", algorithm_name);
    
    int iterations = 1;

    if(size <= 100) {
        iterations = 10000;
    } else if (size <= 1000) {
        iterations = 1000;
    } else if (size < 10000) {
        iterations = 100; 
    }
    
    clock_t start = start_timer();

    for(int i = 0; i < iterations; i++) {
        Node* test_list = copy_list(master_list);
        if(test_list == NULL && master_list != NULL) 
            continue;

        sort_func(&test_list);
        
        free_list(test_list);
    }
    
    double total_time = stop_timer(start);
    
    printf("%.6f seconds\n", total_time);
}