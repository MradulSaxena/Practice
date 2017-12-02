//
//  mergesort.cpp
//  XCODE
//
//  Created by Mradul Saxena on 12/2/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#include "common_incl.h"

//
//merge : merges the two subarrays in to the given result array
//
void merge (vector<int>& A, vector<int>& B, vector<int>& nums) {
    int A_size = static_cast<int>(A.size());
    int B_size = static_cast<int>(B.size());
    
    int i=0, j=0, k=0;
    
    //merge back the elements in the order
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
    
    // check for the remaning elements and copy them
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

//
//mergesort : sorts the given array in ascending order
//
void mergesort(vector<int>& nums) {
    int size = static_cast<int> (nums.size());
    if (size>1) {
        int mid = size/2;
        //split the given array in two halves
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
        
        //mergesort on the divided arrays
        mergesort(A);
        mergesort(B);
        
        //mergeback the divided arrays back in the original array
        merge(A,B,nums);
        
    }
}

void test_mergesort (void)
{
    cout << "\nMerge Sort\n\n";
    vector<int> arr = {45,4,5,-1,6,3,2};
    mergesort(arr);
    
    for (auto i:arr) {
        cout<< i<<" ";
    }
    
    cout<<endl<<endl;
}
