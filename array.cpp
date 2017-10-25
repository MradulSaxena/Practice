//
//  array.cpp
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#include "common_incl.h"
#include "array.h"


int findone(const vector<int> a) {
    int ones = 0;
    int twos = 0;
    int threes = 0;
    
    for (int i=0;i<a.size();i++) {
        twos |= ones & a[i];
        ones ^= a[i];
        threes = ~(ones & twos);
        ones &= threes;
        twos &= threes;
    }
    
    return ones;
}



int findmissing(vector<int>&arr, int start, int high,const int first_val) {
    
    if (start>high) {
        return high+first_val+1;
    }
    
    if (start != (arr[start] - first_val)){
        return start+first_val;
    }
    
    int mid = start+ (high-start)/2;
    
    if ((arr[mid]-first_val) == mid) {
        return findmissing(arr, mid+1, high, first_val);
    }
    
    return findmissing(arr, start, mid, first_val);
}

//
// Kadane's Algorithm is also known as maximum subarray
//
int kadane_algorithm (vector <int>&arr)
{
    int sum = INT_MIN;
    int sum_so_far = INT_MIN;
    
    
    
    return sum;
}


void test_array (void) {
//    vector<int> arr = {4,5,6,7,8,10,11,12};
//    //vector<int> arr = {1,2,3,4,6,7,8,9};
//    cout << "val is "<< findmissing(arr, 0, static_cast<int>(arr.size()-1), arr[0])<< endl;
//
//
//    vector<int>a = {1,1,1,2,2,3,2,3,3,5};
//    cout<< "number is "<< findone(a)<<endl;
    
    vector<int> array = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "maximum_subarray sum is " << kadane_algorithm(array)<<endl;
}

