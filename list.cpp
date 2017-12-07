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

// Structure of random linked list Node
struct RandNode
{
    int data;
    RandNode *next,*random;
    RandNode(int x)
    {
        data = x;
        next = random = NULL;
    }
};

// Utility function to print the list.
void print(RandNode *start)
{
    RandNode *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = "
        << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

//
//clone a list with random poniters in O(1) extra space
//
RandNode * clone(RandNode *head)
{
    if (!head) {
        return NULL;
    }
    RandNode *curr = head;
    RandNode *temp;
    
    //insert a new node next to the original node
    while(curr) {
        temp = curr->next;
        RandNode *newnode = new RandNode(curr->data);
        curr->next = newnode;
        newnode->next = temp;
        curr = temp;
    }
    
    curr = head;
    //copy the random pointers
    while(curr) {
        // copy the random pointer in the new node to the copy of random
        curr->next->random = curr->random->next;
        // move to the next newly added node by
        // skipping an original node
        curr = curr->next?curr->next->next:curr->next;
    }
    
    RandNode * orig_list = head;
    RandNode * cloned_list = head->next;
    temp = cloned_list;

    while(orig_list && temp) {
        orig_list->next = temp?temp->next:NULL;
        orig_list = orig_list?orig_list->next:NULL;
        temp->next = orig_list?orig_list->next:NULL;
        temp = temp->next;

    }
    
    
    return cloned_list;
    
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
    
    RandNode* start = new RandNode(1);
    start->next = new RandNode(2);
    start->next->next = new RandNode(3);
    start->next->next->next = new RandNode(4);
    start->next->next->next->next = new RandNode(5);
    
    // 1's random points to 3
    start->random = start->next->next;
    
    // 2's random points to 1
    start->next->random = start;
    
    // 3's and 4's random points to 5
    start->next->next->random =
    start->next->next->next->next;
    start->next->next->next->random =
    start->next->next->next->next;
    
    // 5's random points to 2
    start->next->next->next->next->random =
    start->next;
    print(start);
    
    cout <<"\n\nCloned List\n";
    RandNode *cloned_list = clone(start);
    print(cloned_list);
    
}

