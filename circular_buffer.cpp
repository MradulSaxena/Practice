//
//  circular_buffer.cpp
//  XCODE
//
//  Created by Mradul Saxena on 3/16/18.
//  Copyright © 2018 Mradul Saxena. All rights reserved.
//

#include "common_incl.h"
#include "circular_buffer.h"


void test_circular_buffer (void)
{
    circularBuffer<uint64_t> cb(2);
    
    cout << "Is empty " << cb.empty() << std::endl;
    
    cb.put(10);
    cb.put(20);
    cb.put(30);
    cout << "Is empty " << cb.empty() << std::endl;
    cout << "Is Full " << cb.full() << std::endl;
    
    cout <<cb.get()<< std::endl;
    cout <<cb.get()<< std::endl;
    cout <<cb.get()<< std::endl;
    cout <<cb.get()<< std::endl;
    
    
}
