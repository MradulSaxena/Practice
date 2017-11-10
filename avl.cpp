//
//  avl.cpp
//  Practice
//
//  Created by Mradul Saxena on 10/3/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//
#include "common_incl.h"
#include "avl.h"

#define LEAF_HEIGHT     1

avlnode_t * getNode (int data)
{
    avlnode_t *newnode = new avlnode_t;
    
    if (!newnode) {
        return nullptr;
    }
    
    newnode->data   = data;
    newnode->height = LEAF_HEIGHT;
    
    newnode->left   = NULL;
    newnode->right  = NULL;
    
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

avlnode_t * insert_node (avlnode_t * root, int data)
{

    // insert_node like a normal BST first
    if (!root) {
        return getNode(data);
    }

    if (root->data > data) {
        root->left = insert_node(root->left, data);
    } else if (root->data < data) {
        root->right = insert_node(root->right, data);
    } else {
        // equal keys are not allowed in BST
        return root;
    }
    
    //update height
    root->height = 1 + max(get_height(root->left),
                           get_height(root->right));
    
    int balance = get_balance_factor(root);
    
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

void delete_node (avlnode_t *root, int data)
{
    if (!root) {
        return;
    }

}
void test_avl (void)
{
    avlnode_t   *root  = NULL;

    root = insert_node(root, 10);
    root = insert_node(root, 20);
    root = insert_node(root, 30);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 25);
    
//  The constructed AVL Tree would be
//      30
//     /  \
//    20   40
//   /  \    \
//  10  25    50
//
    cout <<"\nPreOrder Traversal\n";
    preOrder(root);
    cout <<endl;
}

