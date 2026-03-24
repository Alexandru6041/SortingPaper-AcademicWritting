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
    int* test_array = copy_int_array(array, size);
    printf("%-15s | ", algorithm_name); 

    
    clock_t start = start_timer();

    sort_function(test_array, size);
    double total_time = stop_timer(start);
    
    printf("%.6f seconds\n", total_time);
    free(test_array);
}

void run_list_benchmark(const char* algorithm_name, void (*sort_func)(Node**), Node* master_list) {
    printf("%-15s | ", algorithm_name); 
    
    Node* test_list = copy_list(master_list);
    if(test_list == NULL && master_list != NULL) 
        return;
    
    clock_t start = start_timer();
    sort_func(&test_list);
    double total_time = stop_timer(start);
    
    printf("%.6f seconds\n", total_time);
    free_list(test_list);
}