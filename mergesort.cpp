//
//  mergesort.cpp
//  XCODE
//
//  Created by Mradul Saxena on 12/2/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#include "common_incl.h"

void merge (vector<int>& A, vector<int>& B, vector<int>& nums) {
    int A_size = static_cast<int>(A.size());
    int B_size = static_cast<int>(B.size());
    
    int i=0, j=0, k=0;
    
    while(i<A_size && j<B_size) {
        if (A[i] < B[j]) {
            nums[k] = A[i];
            i++;
            k++;
        } else {
            nums[k] = B[j];
            j++;
            k++;
        }
    }
    
    if (i==A_size) {
        while(j<B_size) {
            nums[k] = B[j];
            j++;
            k++;
        }
    } else {
        while(i<A_size) {
            nums[k] = A[i];
            i++;
            k++;
        }
    }
}
void mergesort(vector<int>& nums) {
    int size = static_cast<int> (nums.size());
    if (size>1) {
        int mid = size/2;
        
        vector<int> A;
        int i = 0;
        while(i<=mid-1) {
            A.push_back(nums[i]);
            i++;
        }
        vector<int> B;
        int j = mid;
        while(j<=size-1) {
            B.push_back(nums[j]);
            j++;
        }
        
        mergesort(A);
        mergesort(B);
        
        merge(A,B,nums);
        
    }
}

void test_mergesort (void)
{
    vector<int> arr = {4,5,6,3,2};
    mergesort(arr);
    
    for (auto i:arr) {
        cout<< i<<endl;
    }
}
