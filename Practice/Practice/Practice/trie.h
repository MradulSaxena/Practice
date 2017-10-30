//
//  trie.h
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#ifndef trie_h
#define trie_h
#include "common_incl.h"

#define ALPHABET_SIZE 26

typedef struct trie_s {
    struct trie_s *children[ALPHABET_SIZE];
    bool is_word;
} trie_t;

trie_t* get_Node(void);

status_t insert(trie_t *root, string word);

void test_trie (void);

#endif /* trie_h */
