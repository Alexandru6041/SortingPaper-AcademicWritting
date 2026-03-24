#ifndef SORT_LIST
#define SORT_LIST
#include "list_utils.h"

void merge_sort_list(Node** head);
void bubble_sort_list(Node** headRef);
void selection_sort_list(Node** headRef);
void insertion_sort_list(Node** headRef);
void radix_sort_list(Node** headRef);

#endif