//
//  avl.h
//  XCODE
//
//  Created by Mradul Saxena on 11/8/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#ifndef avl_h
#define avl_h
// An AVL tree node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};


#endif /* avl_h */
