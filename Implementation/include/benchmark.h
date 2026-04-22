#ifndef BENCHMARK
#define BENCHMARK
#include <stdbool.h>
#include "list_utils.h"

void run_array_benchmark(const char* algorithm_name, void (*sort_function)(int*, int), int *array, int size, bool is_Inefficient);
void run_list_benchmark(const char* algorithm_name, void (*sort_func)(Node**), Node* master_list, int size, bool is_Inefficient);

#endif