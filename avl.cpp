//
//  avl.cpp
//  Practice
//
//  Created by Mradul Saxena on 10/3/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//
#include "common_incl.h"
#include "avl.h"

avlnode_t * getNode (int data) {
    avlnode_t *newnode = new avlnode_t;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}
// A utility function to get maximum of two integers
int max(int a, int b)
{
    return (a > b)? a : b;
}
void preOrder (avlnode_t * root) {
    
    if (root) {
        cout << root->data << " ";
        preOrder (root->left);
        preOrder (root->right);
    }
}

int get_height (avlnode_t *root)
{
    if (!root) {
        return 0;
    }
    
    return root->height;
}

int get_balance_factor(avlnode_t *root)
{
    if (!root) {
        return 0;
    }
    
    return (get_height(root->left) - get_height(root->right));
}

// root->right becomes the root

avlnode_t * left_rotate (avlnode_t * root)
{
    avlnode_t *new_root = root->right;
    avlnode_t *old_root_right = new_root->left;
    
    root->right = old_root_right;
    new_root->left = root;
    
    //Update height
    new_root->height = max (get_height(new_root->left),
                             get_height(new_root->right)) +1;
    
    root->height = max(get_height(root->left),
                       get_height(root->right)) +1;
    
    return new_root;
}

avlnode_t * right_rotate (avlnode_t * root)
{
    avlnode_t *new_root = root->left;
    avlnode_t *old_root_left = new_root->right;
    
    root->left = old_root_left;
    new_root->right = root;
    
    
    //Update height
    new_root->height = max (get_height(new_root->left),
                             get_height(new_root->right)) +1;
    
    root->height = max(get_height(root->left),
                       get_height(root->right)) +1;
    
    return new_root;
}

avlnode_t * insert (avlnode_t * root, int data)
{

    // insert like a normal BST first
    if (!root) {
        return getNode(data);
    }

    if (root->data > data) {
        root->left = insert(root->left, data);
    } else if (root->data < data) {
        root->right = insert(root->right, data);
    } else {
        // equal keys are not allowed in BST
        return root;
    }
    
    //update height
    root->height = 1 + max(get_height(root->left),
                           get_height(root->right));
    
    int balance = get_balance_factor(root);
    
    cout << "Data is " << root->data<< " height is " << balance;
    cout<< endl;

    //left left case
    if (balance > 1 && (data < root->left->data)) {
        return right_rotate(root);
    }
    
    // right right case
    if (balance < -1 && (data > root->right->data) ) {
        return left_rotate(root);
    }
    
    // left right case
    if (balance > 1 && (data > root->left->data)) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    
    // right left case
    if (balance < -1 && (data < root->right->data)) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    
    return root;
}

void test_avl (void)
{
    avlnode_t   *root  = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    preOrder(root);
}

