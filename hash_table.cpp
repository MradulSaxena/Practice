//
//  hash_table.cpp
//  XCODE
//
//  Created by Mradul Saxena on 1/5/18.
//  Copyright © 2018 Mradul Saxena. All rights reserved.
//

#include "hash_table.h"

void test_hash_map (void)
{
    unique_ptr<HashMap<string, int>> Hash = make_unique<HashMap<string, int>>(10);
    if (Hash != nullptr) {
        cout << "hash_map instantiated"<<endl;
    }
}

