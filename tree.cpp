//
//  tree.cpp
//  Practice
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
void bottom_view (node_t *root)
{
    map<int, vector<int>> my_map;
    
    int level = 0;
    
    if (!root) {
        return;
    }
    
    queue<pair<node_t *, int>> hd_q;
    hd_q.push(make_pair(root, level));
    
    while (!hd_q.empty()) {
        pair<node_t *, int> temp = hd_q.front();
        hd_q.pop();
        level = temp.second;
        
        my_map[temp.second].push_back(temp.first->data);
        if (temp.first->left) {
            hd_q.push(make_pair(temp.first->left, level-1));
        }
        
        if (temp.first->right) {
            hd_q.push(make_pair(temp.first->right, level+1));
        }
    }
    
    auto it = my_map.begin();
    while(it!=my_map.end()) {
        for (int i=0;i<it->second.size();i++) {
            cout << " " << it->second[i];
        }
        cout<<endl;
        it++;
    }
    
}
void level_order_view (node_t *root, int level, vector<vector<int>>& sol)
{
    if (!root) {
        return;
    }
    
    if (sol.size() == level) {
        sol.push_back(vector<int>());
    }
    
    sol[level].push_back(root->data);
    if (root->left) {
        level_order_view(root->left, level+1, sol);
    }
    
    if (root->right) {
        level_order_view(root->right, level+1, sol);
    }
}

void vertical_level_view (node_t *root)
{
    map<int, vector<int>> my_map;
    
    int level = 0;
    
    if (!root) {
        return;
    }
    
    queue<pair<node_t *, int>> hd_q;
    hd_q.push(make_pair(root, level));
    
    while (!hd_q.empty()) {
        pair<node_t *, int> temp = hd_q.front();
        hd_q.pop();
        level = temp.second;
        
        my_map[temp.second].push_back(temp.first->data);
        if (temp.first->left) {
            hd_q.push(make_pair(temp.first->left, level-1));
        }
        
        if (temp.first->right) {
            hd_q.push(make_pair(temp.first->right, level+1));
        }
    }
    
    auto it = my_map.begin();
    while(it!=my_map.end()) {
        for (int i=0;i<it->second.size();i++) {
            cout << " " << it->second[i];
        }
        cout<<endl;
        it++;
    }

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
//    int max_level = INT_MIN;
//    node_t *root = newNode(12);
//    root->left = newNode(9);
//    root->right = newNode(30);
//    root->right->left = newNode(25);
//    root->right->right = newNode(40);
//    
//    cout << "\nLeft View Of the Tree is ";
//    print_left_view(root, 0, &max_level);
//    cout <<endl;
//    
//    cout << "\nTree is BST "<< check_bst(root);
//    cout <<endl;
//
    vector<vector<int>> sol;
    node_t *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left= newNode(10);
    root->right->right->left->right= newNode(11);
    root->right->right->left->right->right= newNode(12);
    
    cout << "\nBottom View Of the Tree is ";
    vertical_level_view(root);
    cout <<endl;
    level_order_view(root, 0, sol);
    
    for (int i=0;i<sol.size();i++) {
        for (int j=0;j<sol[i].size();j++) {
            cout<< sol[i][j]<< " ";
        }
        cout<<endl;
    }
    
}
