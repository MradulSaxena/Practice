//
//  hash_table.h
//  XCODE
//
//  Created by Mradul Saxena on 3/28/18.
//  Copyright © 2018 Mradul Saxena. All rights reserved.
//

#ifndef hash_table_h
#define hash_table_h
#include "common_incl.h"

template <typename K, typename V>
class HashNode {
    K   key_;
    V   value_;
    HashNode *next;
public:
    HashNode(K key, V value) {
        key_   = key;
        value_ = value;
        next   = NULL;
    }
};

template <typename K, typename V>
class HashMap {
public:
    HashMap(int size) {
        _size = size;
        _table = new HashNode<K, V>*[size]();
    }
    int hashFunc(int key);

    bool get(const K &key, V &value) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *entry = _table[hashValue];
            
        while (entry != NULL) {
            if (entry->getKey() == key) {
                value = entry->getValue();
                return true;
            }
            entry = entry->getNext();
        }
        return false;
    }

private:
    HashNode<K, V> **_table;
    int _size;
};

void test_hash_map(void);
#endif /* hash_table_h */
