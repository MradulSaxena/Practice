//
//  tree.cpp
//  XCODE
//
//  Created by Mradul Saxena on 10/30/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//


#include "tree.h"

node_t * newNode (int data) {
    node_t *newnode = new node_t;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    
    return newnode;
}

void print_left_view (node_t *root, int level, int *max)
{
    if (!root) {
        return;
    }
    
    if (*max<level) {
        cout<< root->data << endl;
        *max = level;
    }
    
    print_left_view(root->left, level+1, max);
    print_left_view(root->right, level+1, max);
}

//
//check_bst: checks if the tree is a BST
//
bool check_bst (node_t *root)
{
    static node_t *prev = nullptr;
    
    if (!root) {
        return true;
    }
    if (!check_bst(root->left)) {
        return false;
    }
    
    if (prev && prev->data >= root->data) {
        return false;
    }
    
    prev = root;
    return (check_bst(root->right));

}
void test_tree (void)
{
    int max_level = INT_MIN;
    node_t *root = newNode(12);
    root->left = newNode(9);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);
    
    
    print_left_view(root, 0, &max_level);
    cout << "\nTree is BST "<< check_bst(root);
    
}
