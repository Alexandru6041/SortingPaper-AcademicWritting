#include <stdio.h>
#include <stdlib.h>
#include "sort_list.h"
#include "list_utils.h"

void bubble_sort_list(Node** headRef) {
    if (*headRef == NULL) return;
    int swapped;
    Node* ptr1;
    Node* lptr = NULL; 

    do{
        swapped = 0;
        ptr1 = *headRef;

        while(ptr1->next != lptr) {
            if(ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
}

void selection_sort_list(Node** headRef) {
    Node* temp = *headRef;

    while (temp != NULL) {
        Node* min = temp;
        Node* r = temp->next;

        while (r != NULL) {
            if (min->data > r->data) {
                min = r;
            }
            r = r->next;
        }

        if (min != temp) {
            int x = temp->data;
            temp->data = min->data;
            min->data = x;
        }
        temp = temp->next;
    }
}

void insertion_sort_list(Node** headRef) {
    Node* sorted = NULL;
    Node* current = *headRef;

    while (current != NULL) {
        Node* next = current->next;

        if(sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } 
        else {
            Node* temp = sorted;
            while(temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = next;
    }
    *headRef = sorted;
}