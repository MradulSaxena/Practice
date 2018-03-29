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

template <typeda>
class HashNode {
    K   key_;
    K   value_;
    HashNode *next;
public:
    HashNode(K key, K Value):key_(key), value_(value), next(NULL);
};

template <class T>
class HashMap {
public:
    int hash_function(int key);
private:
    std::unique_ptr<HashNode<T[]>> _table;
    int size;
    
    
};

#endif /* hash_table_h */
