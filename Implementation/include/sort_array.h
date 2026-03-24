#ifndef SORT_ARRAY_H
#define SORT_ARRAY_H


//(O(n^2))
void bubble_sort(int *arr, int size);
void insertion_sort(int *arr, int size);

//O(n*log(n))
void merge_sort(int *arr, int size);
void quick_sort(int *arr, int size);

void selection_sort(int* arr, int size);
void heap_sort(int* arr, int size);

void radix_sort(int *arr, int size);
void shell_sort(int *arr, int size);

#endif