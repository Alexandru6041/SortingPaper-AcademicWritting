#include "variables.h"
#include "data_gen.h"
#include "list_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <ittnotify.h>
#include <stdbool.h>

__itt_domain* domain = NULL;

static clock_t start_timer() {
    return clock();
}

static double stop_timer(clock_t start_time) {
    clock_t end_time = clock();

    return (double)(end_time - start_time) / CLOCKS_PER_SEC;
}

void run_array_benchmark(const char* algorithm_name, void (*sort_function)(int*, int), int *array, int size, bool is_Inefficient){
    long long target_ops = 1000000;
    int iterations = (size < target_ops) ? (target_ops / size) : 1;

    if (is_Inefficient && size > 100000) {
        printf(COLOR_RED "%-15s | SKIPPED (Too slow for size %d)\n" NORMAL_COLOR, algorithm_name, size);
        return;
    }

    if (is_Inefficient && size > 5000) {
        iterations = 1; 
    }
    
    if(domain == NULL) {
        domain = __itt_domain_create("SortingAnalysis");
    }

    char task_label[128];
    snprintf(task_label, 128, "Array_%s_%d", algorithm_name, size);
    __itt_string_handle* handle = __itt_string_handle_create(task_label);
    
    printf("%-15s | ", algorithm_name);

    __itt_task_begin(domain, __itt_null, __itt_null, handle);

    clock_t start = start_timer();

    for(int i = 0; i < iterations; i++) {
        int* test_array = copy_int_array(array, size);
        
        sort_function(test_array, size);
        
        free(test_array);
    }
    

    double total_time = stop_timer(start);
    __itt_task_end(domain);
    
    printf("%.6f seconds\n", total_time);
}

void run_list_benchmark(const char* algorithm_name, void (*sort_func)(Node**), Node* master_list, int size, bool is_Inefficient) {
    long long target_ops = 1000000;
    int iterations = (size < target_ops) ? (target_ops / size) : 1;

    if(is_Inefficient && size > 100000) {
        printf(COLOR_RED "%-15s | SKIPPED (Too slow for size %d)\n" NORMAL_COLOR, algorithm_name, size);
        return;
    }

    if(is_Inefficient && size > 5000) {
        iterations = 1; 
    }
    
    if(domain == NULL){
        domain = __itt_domain_create("SortingAnalysis");
    }

    char task_label[128];
    snprintf(task_label, 128, "List_%s_%d", algorithm_name, size);
    __itt_string_handle* handle = __itt_string_handle_create(task_label);

    printf("%-15s | ", algorithm_name);

    __itt_task_begin(domain, __itt_null, __itt_null, handle);

    clock_t start = start_timer();

    for(int i = 0; i < iterations; i++) {
        Node* test_list = copy_list(master_list);
        if(test_list == NULL && master_list != NULL) 
            continue;

        sort_func(&test_list);
        
        free_list(test_list);
    }
    
    double total_time = stop_timer(start);
    __itt_task_end(domain);
    
    printf("%.6f seconds\n", total_time);
}