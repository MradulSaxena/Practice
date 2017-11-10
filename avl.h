//
//  avl.h
//  Practice
//
//  Created by Mradul Saxena on 11/8/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#ifndef avl_h
#define avl_h

// An AVL tree node
typedef struct avlnode_s
{
    int data;
    struct avlnode_s *left;
    struct avlnode_s *right;
    int height;
}avlnode_t;

void test_avl (void);
#endif /* avl_h */
