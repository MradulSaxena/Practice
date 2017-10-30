//
//  trie.cpp
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//


#include "trie.h"

trie_t * get_Node (void)
{
    trie_t * node = new trie_t;
    memset (node, 0, sizeof(trie_t));
    return node;
}

status_t search (trie_t *root, string word)
{
    int         size    = 0;
    trie_t      *crawl  = root;
    status_t    status  = EOK;
    
    if (!crawl) {
        return EPARAM;
    }
    
    size = static_cast<int>(word.length());
    for (int i=0; i<size; i++) {
        int index = word[i] - 'a';
        if (!crawl->children[index]) {
            cout<< "Not Found\n";
            return EOK;
        }
        
        crawl = crawl->children[index];
    }
    
    if (crawl->is_word) {
        cout<< word << " is present in the trie\n";
    } else {
        cout<< "Not Found\n";
    }
    
    return status;
    
}
status_t insert (trie_t *root, string word) {
    int         size    = 0;
    trie_t      *crawl  = root;
    status_t    status  = EOK;
    
    if (!crawl) {
        return EPARAM;
    }
    
    size = static_cast<int>(word.length());
    
    for (int i=0; i<size; i++) {
        int index = word[i] - 'a';
        if (!crawl->children[index]) {
            crawl->children[index] = get_Node();
        }
        crawl = crawl->children[index];
    }
    
    crawl->is_word = true;
    return status;
}

void test_trie (void)
{
    status_t status = EOK;
    vector<string> keys = { "the", "a", "there",
                            "answer", "any", "by",
                            "bye", "their" };
    trie_t *root = get_Node();

    for (string i:keys) {
        status = insert(root, i);
        if (status != EOK) {
            cout << "Trie insert failed for key " << i;
        }
    }
    
    string word = "a";
    status = search(root, word);
    if (status != EOK) {
        cout << "search for word " << word << " failed\n";
    }
}
