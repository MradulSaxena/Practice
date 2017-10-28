//
//  trie.h
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#ifndef trie_h
#define trie_h


#define ALPHABET_SIZE 26

typedef struct trie_s {
    struct trie_s *children[ALPHABET_SIZE];
    bool is_word;
} trie_t;


bool insert(trie_t *root, string word);
void print_trie(trie_t *root);

#endif /* trie_h */
