//
//  tree.h
//  XCODE
//
//  Created by Mradul Saxena on 10/30/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#ifndef tree_h
#define tree_h
#include "common_incl.h"

typedef struct  node_s {

    int data;
    struct node_s *left;
    struct node_s *right;
}node_t;

void test_tree (void);

#endif /* tree_h */
