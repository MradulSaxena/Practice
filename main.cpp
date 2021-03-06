//
//  main.cpp
//  Practice
//
//  Created by Mradul Saxena on 9/22/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#include "common_incl.h"
#include "heapsort.h"
#include "quicksort.h"
#include "string.h"
#include "list.h"
#include "array.h"
#include "trie.h"
#include "tree.h"
#include "avl.h"
#include "mergesort.h"
#include "bit_magic.h"
#include "circular_buffer.h"
#include "hash_table.h"

template <typename T, typename S>
auto maxof (T a, S b) -> decltype(a+b) {
    return a+b;
}

int main(int argc, const char * argv[]) {
    
//    test_heapsort();
//
//    test_quicksort();
//    
//    test_mergesort();
//
//    test_string();
//
//    test_list();

//    test_array();

//    test_trie();
//
//    test_avl();
//
//    test_tree();
    
//    test_bit_magic();
    test_hash_map();
    
    test_circular_buffer();
    return 0;
}
