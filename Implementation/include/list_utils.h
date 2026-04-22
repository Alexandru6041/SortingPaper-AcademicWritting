#ifndef LIST_UTILS_H
#define LIST_UTILS_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** head_ref, int new_data);
void print_list(Node* node);

Node* array_to_list(int* arr, int size);
Node* copy_list(Node* head);
void free_list(Node* head);

#endif