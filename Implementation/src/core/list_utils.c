#include <stdlib.h>
#include <stdio.h>
#include "list_utils.h"

void push(Node** head_ref, int new_data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// void print_list(Node* node){
//     int count = 0;
//     while (node != NULL && count < 15){
//         printf("%d -> ", node->data);
//         node = node->next;
//         count++;
//     }
//     if(node != NULL) 
//         printf("... ");

//     printf("NULL\n");
// }

Node* array_to_list(int* arr, int size) {
    Node* head = NULL;
    for (int i = size - 1; i >= 0; i--) {
        push(&head, arr[i]);
    }
    return head;
}

Node* copy_list(Node* head) {
    if(head == NULL) 
        return NULL;
    
    Node* new_head = NULL;
    Node* tail = NULL;
    Node* current = head;
    
    while(current != NULL) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = current->data;
        new_node->next = NULL;
        
        if(new_head == NULL) {
            new_head = new_node;
            tail = new_node;
        } 
        else {
            tail->next = new_node;
            tail = new_node;
        }
        current = current->next;
    }
    return new_head;
}

void free_list(Node* head) {
    Node* tmp;
    while(head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}