#include <stdio.h>
#include <stdlib.h>
#include "sort_list.h"

static Node* sortedMerge(Node* a, Node* b) {
    Node dummy; 
    Node* tail = &dummy;
    dummy.next = NULL;

    while(a != NULL && b != NULL) {
        if(a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } 
        else{
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a != NULL) ? a : b;
    return dummy.next;
}


///cutting the list in half 
static void frontBackSplit(Node* source, Node** frontRef, Node** backRef) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    while(fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

void merge_sort_list(Node** headRef) {
    Node* head = *headRef;
    Node* a;
    Node* b;

    if((head == NULL) || (head->next == NULL)) {
        return;
    }

    frontBackSplit(head, &a, &b);

    merge_sort_list(&a);
    merge_sort_list(&b);

    *headRef = sortedMerge(a, b);
}
