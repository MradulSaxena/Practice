//
//  heapsort.cpp
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//
#include "common_incl.h"
#include "heapsort.h"

void test_heapsort (void)
{
        cout <<"\nHeap Sort\n" <<endl;
        vector<int> arr = {4,5,6,3,2};
        heapSort obj;
        obj.heapsort(arr);


        for (int i: arr) {
            cout<< i <<" ";
        }

        cout<<endl;
}

