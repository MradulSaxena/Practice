//
//  common_incl.h
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#ifndef common_incl_h
#define common_incl_h
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <new>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>
#include <stdlib.h>
#include <map>

using namespace std;

typedef enum status {
    EOK,
    EFAIL,
    EMEM,
    EPARAM,
    EMAX
} status_t;

typedef struct  Node_s {
    
    int data;
    struct Node_s *left;
    struct Node_s *right;
    struct Node_s *next;
}Node_t;

#endif /* common_incl_h */
