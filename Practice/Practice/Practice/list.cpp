//
//  list.cpp
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//
#include "common_incl.h"
#include "list.h"

void addNode(Node_t **head, int data) {
    
    Node_t *temp = (Node_t *)malloc (sizeof(Node_t));
    
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void printlist(Node_t *head) {
    Node_t *temp = head;
    while(temp) {
        cout<<temp->data<< " ";
        temp = temp->next;
    }
    cout<<endl;
}

void reverse(Node_t **head) {
    
    Node_t *new_head = NULL;
    Node_t *temp = *head;
    Node_t *temp1 = temp;
    
    if (!temp) {
        return;
    }
    
    while (temp) {
        temp1 = temp->next;
        temp->next = new_head;
        new_head=temp;
        temp=temp1;
    }
    
    *head = new_head;
}

void remove(Node_t **head, int value) {
    
    Node_t *temp = *head;
    if (!temp) {
        return;
    }
    
    if (temp->data == value) {
        temp = temp->next;
        *head = temp;
        remove(head,value);
    } else if (temp->next &&
               temp->next->data==value) {
        temp->next = temp->next->next;
        remove(head,value);
    } else {
        temp=temp->next;
        remove(&temp,value);
    }
}



void test_list (void) {
    
    Node_t *head = NULL;
    
    addNode(&head, 20);
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 20);
    addNode(&head, 40);
    addNode(&head, 20);
    addNode(&head, 50);
    addNode(&head, 20);
    addNode(&head, 20);
    addNode(&head, 20);
    addNode(&head, 70);
    printlist(head);
    reverse(&head);
    printlist(head);
    remove(&head, 20);
    printlist(head);
}
