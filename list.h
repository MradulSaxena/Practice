//
//  list.h
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#ifndef list_h
#define list_h


typedef struct Node_s {
    int data;
    struct Node_s *next;
}Node_t;


void printlist(Node_t *head);
void remove(Node_t **head, int value);
void addNode(Node_t **head, int data);
void reverse(Node_t **head);

void test_list(void);

#endif /* list_h */
