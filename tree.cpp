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

// Returns true if trees with roots as root1 and root2 are mirror
bool isMirror( Node_t *root1,  Node_t *root2)
{
    // If both trees are emptu, then they are mirror images
    if (root1 == NULL && root2 == NULL)
        return true;
    
    // For two trees to be mirror images, the following three
    // conditions must be true
    // 1 - Their root node's key must be same
    // 2 - left subtree of left tree and right subtree
    //      of right tree have to be mirror images
    // 3 - right subtree of left tree and left subtree
    //      of right tree have to be mirror images
    if (root1 && root2 && root1->data == root2->data)
        return isMirror(root1->left, root2->right) &&
        isMirror(root1->right, root2->left);
    
    // if neither of above conditions is true then root1
    // and root2 are not mirror images
    return false;
}

//
//maxDepth or height of the binary tree
//
int maxDepth (Node_t *node)
{
    if (node==NULL) {
        return 0;
    }
    
    /* compute the depth of each subtree */
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);
        
    /* use the larger one */
    if (lDepth > rDepth)
        return(lDepth+1);
    else
        return(rDepth+1);
}

//
//max_path_sum : computes the maximum sum between all the nodes
//
int max_path_sum (Node_t *root, int &res)
{
    if (!root) {
        return 0;
    }
    
    int final_val = 0;
    int left_sum = max_path_sum(root->left,res);
    int right_sum = max_path_sum(root->right,res);
    
    // find the local maximum
    final_val = max(root->data, max(root->data+left_sum, root->data+right_sum));
    
    // compare with the global max
    res = max(res, max(final_val, root->data+left_sum+right_sum));
    
    return final_val;
}

//
//preorder:
//
void preorder (Node_t *root)
{
    if (!root) {
        return;
    }
    
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//
//inorder:
//
void inorder (Node_t *root)
{
    if (!root) {
        return;
    }
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//
//preorder_to_bst: convert preorder traversal to BST
//
Node_t *preorder_to_bst (vector<int> preorder_vector)
{
    int size = static_cast<int>(preorder_vector.size());
    
    if (size == 0) {
        return NULL;
    }
    
    Node_t * root = newNode(preorder_vector[0]);
    
    if (size>1) {
        int left_index_start = 1;
        int left_index_end = 1;
        while(root->data >preorder_vector[left_index_end]) {
            left_index_end++;
        }
        vector<int> new_left(preorder_vector.begin()+left_index_start,
                             preorder_vector.begin()+(left_index_end));
        root->left  = preorder_to_bst(new_left);
        
        vector<int> new_right(preorder_vector.begin()+left_index_end,
                              preorder_vector.end());
        root->right = preorder_to_bst(new_right);
    }
    
    return root;
}

//
//closest_node: for a non-empty BST find the closest node
//
int closest_node(Node_t *root, int target)
{
    
    int     returned_val = INT_MAX;
    Node_t *next = nullptr;
    
    if (root->data == target) {
        return target;
    }
    
    if (target<root->data) {
        next = root->left;
    } else {
        next = root->right;
    }
    
    if (!next) {
        return root->data;
    }
    
    returned_val = closest_node(next , target);
    
    return (abs(target - root->data)) < (abs(target - returned_val))
            ? root->data : returned_val;
}

//
//get_height : returns the height of a binary tree
//
int get_height (Node_t *root)
{
    if (!root) {
        return 0;
    }
    return (max(get_height(root->left),get_height(root->right))+1);
}

//
//get_width: return the widht of a full binary tree.
//           width is the max(left, right)*2+1
//
int get_width (Node_t *root)
{
    if (!root) {
        return 0;
    }
    return ((max(get_width(root->left),get_width(root->right))*2)+1);
}

void get_help (vector<vector<string>>& my_vector, Node_t * root, int level,
               int left, int right)
{
    if (!root) {
        return;
    }
    
    int mid = left+(right-left)/2;
    
    my_vector[level][mid] = to_string(root->data);
    get_help(my_vector, root->left, level+1, left, mid-1);
    get_help(my_vector, root->right, level+1, mid+1, right);
}

/*
 Print a binary tree in an m*n 2D string array following these rules:
 
 The row number m should be equal to the height of the given binary tree.
 The column number n should always be an odd number.
 The root node's value (in string format) should be put in the exactly middle of
 the first row it can be put. The column and the row where the root  node belongs
 will separate the rest space into two parts (left-bottom part and right-bottom
 part). You should print the left subtree in the left-bottom part and print the
 right subtree in the right-bottom part. The left-bottom part and the right-bottom
 part should have the same size. Even if one subtree is none while the other is
 not, you don't need to print anything for the none subtree but still need to
 leave the space as large as that for the other subtree. However, if two
 subtrees are none, then you don't need to leave space for both of them.
 Each unused space should contain an empty string "".
 Print the subtrees following the same rules.
 */
void print_binary_tree (Node_t *root) {
    
    if (!root) {
        return;
    }
    
    int h = get_height(root);
    int w = get_width(root);
    vector<vector<string>> my_vector(h, vector<string>(w, "\"\""));
    
    get_help(my_vector, root, 0 , 0 , w-1);
    
    for (int i=0;i<h;i++) {
        for (int j=0;j<w;j++) {
            cout<< my_vector[i][j] << " ";
        }
        cout<<endl;
    }
    
}

typedef struct connect_node_s {
    struct connect_node_s *left;
    struct connect_node_s *right;
    struct connect_node_s *nextright;
    int data;
}connect_node;

//
//getnextright : helper function to get the next right element for a given node
//
connect_node *
getnextright(connect_node *node)
{
    if (!node) {
        return NULL;
    }
    
    connect_node *temp =node->nextright;
    
    while (temp != NULL) {
        if (temp->left) {
            return temp->left;
        }
        
        if (temp->right) {
            return temp->right;
        }
        
        temp = temp->nextright;
    }
    
    return temp;
}

//
//connect_same_level
//
void connect_same_level (connect_node *root)
{
    if (!root) {
        return;
    }
}

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
    /* Constructing below tree
           20
          /   \
         8     22
        / \    / \
       5   3  4   25
          / \
         10 14
     */
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
    
    cout<<"\nHeight of the binary tree \n";
    cout << maxDepth(root);
    cout<<endl;
    
    Node_t *root1 = newNode(10);
    root1->left        = newNode(2);
    root1->right       = newNode(10);
    root1->left->left  = newNode(20);
    root1->left->right = newNode(1);
    root1->right->right = newNode(-25);
    root1->right->right->left   = newNode(3);
    root1->right->right->right  = newNode(4);

    cout<<"\nMaximum Path Sum\n";
    int result_val = INT_MIN;
    max_path_sum(root1, result_val);
    cout<<"Maximum Path Sum is " << result_val;
    cout<<endl;
    
    cout<<"\npreorder_to_bst\n";
    vector<int> preorder_vector = {10, 5, 1, 7, 45, 40, 50};
    Node_t *bst = preorder_to_bst(preorder_vector);
    cout<<"\nInorder Traversal\n";
    inorder(bst);
    cout<<"\nPreorder Traversal\n";
    preorder(bst);
    cout<<endl;
    
    cout<<"\nClosest Node in BST \n";
    cout<< "The Closest node in the BST is "<< closest_node(root1,-14) <<endl;
    cout<<endl;
    
    cout<<"\nPrint Binary Tree\n";
    print_binary_tree(root1);
    cout<<endl;
}
