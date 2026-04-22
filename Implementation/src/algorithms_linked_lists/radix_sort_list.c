#include <stdio.h>
#include <stdlib.h>
#include "sort_list.h"

void radix_sort_list(Node** headRef) {
    if (*headRef == NULL || (*headRef)->next == NULL) 
        return;

    int max = (*headRef)->data;
    Node* curr = (*headRef)->next;
    while (curr != NULL) {
        if (curr->data > max) max = curr->data;
        curr = curr->next;
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        
        Node* buckets[10] = {NULL};
        Node* tails[10] = {NULL};
        
        curr = *headRef;
        while (curr != NULL) {
            int digit = (curr->data / exp) % 10;
            
            Node* next_node = curr->next;
            curr->next = NULL; 

            if (buckets[digit] == NULL) {
                buckets[digit] = curr;
                tails[digit] = curr;
            } 
            else {
                tails[digit]->next = curr;
                tails[digit] = curr;
            }
            curr = next_node;
        }

        Node* newHead = NULL;
        Node* newTail = NULL;
        
        for (int i = 0; i < 10; i++) {
            if (buckets[i] != NULL) {
                if (newHead == NULL) {
                    newHead = buckets[i];
                    newTail = tails[i];
                } else {
                    newTail->next = buckets[i];
                    newTail = tails[i];
                }
            }
        }
        *headRef = newHead;
    }
}