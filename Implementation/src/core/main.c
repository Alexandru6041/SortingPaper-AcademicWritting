#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data_gen.h"
#include "sort_array.h" 
#include "variables.h"
#include "benchmark.h"
#include "list_utils.h"
#include "sort_list.h"

int main() {
    srand(time(NULL));

    Type array_types[] = {RANDOM, SORTED, REVERSED, ALMOST_SORTED, MIXED, FLAT}, number_array_types = sizeof(array_types) / sizeof(array_types[0]);

    for(int i = 0; i < number_sizes; i++){
        int current_size = SIZES[i];

        printf("\n" COLOR_GREEN "Benchmarking for array size: %d" NORMAL_COLOR "\n", current_size);
        
        for(int j = 0; j < number_array_types; j++){
            Type current_array_type = array_types[j];
            int *master_array = generate_random_int_array(current_size, current_array_type);
            
            printf("\n" COLOR_GREEN "Element Distribution: %s" NORMAL_COLOR "\n", get_array_type_name(current_array_type));
            print_int_array(master_array, current_size);

            printf(YELLOW "\n\nARRAYS\n" NORMAL_COLOR);

            run_array_benchmark("Merge Sort", merge_sort, master_array, current_size);
            run_array_benchmark("Quick Sort", quick_sort, master_array, current_size);
            run_array_benchmark("Heap Sort", heap_sort, master_array, current_size);
            run_array_benchmark("Radix Sort", radix_sort, master_array, current_size);
            run_array_benchmark("Shell Sort", shell_sort, master_array, current_size);
            run_array_benchmark("Insertion Sort", insertion_sort, master_array, current_size);
            run_array_benchmark("Selection Sort", selection_sort, master_array, current_size);
            run_array_benchmark("Bubble Sort", bubble_sort, master_array, current_size);

            printf("\n==================================================\n");

            printf(YELLOW "\nLINKED LISTS\n" NORMAL_COLOR);
            
            Node* master_list = array_to_list(master_array, current_size);
            run_list_benchmark("Merge Sort", merge_sort_list, master_list);
            run_list_benchmark("Radix Sort", radix_sort_list, master_list);
            run_list_benchmark("Insertion Sort", insertion_sort_list, master_list);
            run_list_benchmark("Selection Sort", selection_sort_list, master_list);
            run_list_benchmark("Bubble Sort", bubble_sort_list, master_list);

            printf("\n|==================================================|\n\n\n");
            free_list(master_list);
            free(master_array);


        }
        printf("\n\n\n|==================================================|\n\n\n");
    }

    printf("\n" COLOR_GREEN "Teste finalizate!" NORMAL_COLOR "\n");

    return 0;
}