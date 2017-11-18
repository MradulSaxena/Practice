//
//  tree.cpp
//  Practice
//
//  Created by Mradul Saxena on 10/30/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//


#include "tree.h"
#include "list.h"

Node_t * newNode (int data) {
    Node_t *newnode = new Node_t;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    
    return newnode;
}

void print_left_view (Node_t *root, int level, int *max)
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
// spiral_level_order : prints the spiral type of level order traversal
//
void spiral_level_order (Node_t *root, int level, vector<deque<int>>& sol)
{
    if (!root) {
        return;
    }
    
    if (sol.size() == level) {
        sol.push_back(deque<int>());
    }
   
    if (level % 2 == 0) {
        sol[level].push_front(root->data);
    } else {
        sol[level].push_back(root->data);
    }
    
    spiral_level_order(root->left, level+1, sol);
    spiral_level_order(root->right, level+1, sol);
}

//
// bottom_view : print the bottom view of a binary tree
//               idea is to do a vertical level order traversal and take
//               the last element of each level vector
//
void bottom_view (Node_t *root)
{
    map<int, vector<int>> my_map;
    
    int level = 0;
    
    if (!root) {
        return;
    }
    
    queue<pair<Node_t *, int>> hd_q;
    hd_q.push(make_pair(root, level));
    
    while (!hd_q.empty()) {
        pair<Node_t *, int> temp = hd_q.front();
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
        cout << " " << it->second[it->second.size()-1];
        cout<<endl;
        it++;
    }
}

//
// level_order_view : print the level order traversal of a binary tree
//
void level_order_view (Node_t *root, int level, vector<vector<int>>& sol)
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

//
// vertical_level_view : print the vertical level traversal
//
void vertical_level_view (Node_t *root)
{
    map<int, vector<int>> my_map;
    
    int level = 0;
    
    if (!root) {
        return;
    }
    
    queue<pair<Node_t *, int>> hd_q;
    hd_q.push(make_pair(root, level));
    
    while (!hd_q.empty()) {
        pair<Node_t *, int> temp = hd_q.front();
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
//
//
Node_t *lca(Node_t *root, Node_t *p, Node_t *q)
{

    if (!root || !p || !q) {
        return NULL;
    }
    
    if (root->data == p->data ||
        root->data == q->data) {
        return root;
    }
    
    Node_t* left = lca(root->left,p,q);
    Node_t* right = lca(root->right,p,q);
    
    if (left && right) {
        return root;
    }
    
    if (!left) {
        return right;
    }
    
    return left;
}

//
//check_bst: checks if the tree is a BST
//
bool check_bst (Node_t *root)
{
    static Node_t *prev = nullptr;
    
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

//
//
//
Node_t *previous;
void flatten (Node_t *root)
{
    if (!root) {
        return;
    }
        
    flatten(root->right);
    flatten(root->left);
    root->right = previous;
    previous = root;
    root->left = NULL;
}

void tree_to_linked_list (Node_t *root, Node_t **head)
{
    if (!root) {
        return;
    }
    
    tree_to_linked_list(root->right, head);
    
    root->right = *head;
    
    if (*head) {
        (*head)->left = root;
    }
    
    *head = root;
    
    tree_to_linked_list(root->left, head);
}
//
// test_tree: driver function to test tree TC
//
void test_tree (void)
{
//    int max_level = INT_MIN;
//    Node_t *root = newNode(12);
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
    
    Node_t *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    
    
//    Node_t *root = newNode(1);
//    root->left = newNode(2);
//    root->right = newNode(3);
//    root->left->left = newNode(4);
//    root->left->right = newNode(5);
//    root->right->left = newNode(6);
//    root->right->right = newNode(7);
//    root->right->left->right = newNode(8);
//    root->right->right->right = newNode(9);
//    root->right->right->left= newNode(10);
//    root->right->right->left->right= newNode(11);
//    root->right->right->left->right->right= newNode(12);
    
    
    
    cout << "\nBottom View Of the Tree is \n";
    bottom_view(root);
    cout <<endl;
    
    cout << "\nVertical Level Order Traversal \n";
    vertical_level_view(root);
    cout <<endl;
    
    cout<<"\nLevel Order Traversal\n";
    level_order_view(root, 0, sol);
    
    for (int i=0;i<sol.size();i++) {
        for (int j=0;j<sol[i].size();j++) {
            cout<< sol[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    cout<<"\nSpiral Order Traversal\n";
    vector<deque<int>> solution;
    spiral_level_order(root, 0, solution);
    
    for (int i=0;i<solution.size();i++) {
        auto it = solution[i].begin();
        while (it != solution[i].end()) {
            cout<< *it<< " ";
            it++;
        }
        cout<<endl;
    }
    cout<<endl;
    
    cout<<"\nConnect Nodes at same level\n";
    //connect_same_level(root);
    
    cout<<"\nLCA\n";
    Node_t *res = lca(root, root->left->left , root->right->left);
    int result = res?res->data:0;
    cout << "LCA is " << result;
    cout<<endl;
    
    cout<<"\nFlatten a tree to a linked list\n";
    flatten(root);
    printlist(root);
    cout<<endl;
    
    /* Constructing below tree
            5
          /   \
         3     6
        / \     \
       1   4     8
      / \       / \
     0   2     7   9
    */
    Node_t *newroot = newNode(5);
    newroot->left = newNode(3);
    newroot->right = newNode(6);
    newroot->left->left = newNode(1);
    newroot->left->right = newNode(4);
    newroot->right->right = newNode(8);
    newroot->left->left->left = newNode(0);
    newroot->left->left->right = newNode(2);
    newroot->right->right->left = newNode(7);
    newroot->right->right->right = newNode(9);
    cout<<"\nBinary Tree to List (Great List Problem)\n";
    Node_t *list_head = nullptr;
    tree_to_linked_list(newroot, &list_head);
    printlist(list_head);
    cout<<endl;
    
}
