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
    std::unique_ptr<circularBuffer<uint64_t>> CirBufPtr;
    
    cout << "Is empty " << CirBufPtr->empty() << std::endl;
    
    CirBufPtr->put(10);
    CirBufPtr->put(20);
    CirBufPtr->put(30);
    cout << "Is empty " << CirBufPtr->empty() << std::endl;
    cout << "Is Full " << CirBufPtr->full() << std::endl;
    
    cout <<CirBufPtr->get()<< std::endl;
    cout <<CirBufPtr->get()<< std::endl;
    cout <<CirBufPtr->get()<< std::endl;
    cout <<CirBufPtr->get()<< std::endl;
}
