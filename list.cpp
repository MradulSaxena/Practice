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
    temp->right = *head;
    *head = temp;
}

void printlist(Node_t *head) {
    Node_t *temp = head;
    while(temp) {
        cout<<temp->data<< " ";
        temp = temp->right;
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
        temp1 = temp->right;
        temp->right = new_head;
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
        temp = temp->right;
        *head = temp;
        remove(head,value);
    } else if (temp->right &&
               temp->right->data==value) {
        temp->right = temp->right->right;
        remove(head,value);
    } else {
        temp=temp->right;
        remove(&temp,value);
    }
}

//stl comparator function
struct cmp {
    bool operator()(const Node_t *p, const Node_t *q) {
        return p->data > q->data;
    }
};

//
// merge k lists : merges k lists using heap
//
Node_t * mergek_lists (vector<Node_t *> lists)
{
    priority_queue<Node_t *, vector<Node_t *>, cmp> q;
    Node_t *tail,*head;
    
    for (auto i:lists) {
        if (i) q.push(i);
    }
    if (q.empty()) return NULL;
    
    head = tail = q.top();
    q.pop();
    if (head->next) q.push(head->next);
    while(!q.empty()) {
        tail->next = q.top();
        q.pop();
        tail = tail->next;
        if (tail->next) q.push(tail->next);
    }
    
    return head;
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

