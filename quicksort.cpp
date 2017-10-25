//
//  quicksort.cpp
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//
#include "common_incl.h"
#include "quicksort.h"

void test_quicksort (void) {

    vector<int> arr1 = {22,14,36,24,15,11,56,434,42,56,2,45,4};
    cout<<"\nQuick Sort\n" <<endl;
    quickSort qsort;
    qsort.quicksort(arr1,0,static_cast<int>(arr1.size()-1));

    for (int i: arr1) {
        cout<< i << endl;
    }
    
}
