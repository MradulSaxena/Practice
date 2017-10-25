//
//  heapsort.h
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#ifndef heapsort_h
#define heapsort_h


class heapSort {
public:
    void swap (int &a, int &b) {
        a = a+b;
        b = a-b;
        a = a-b;
    }
    
    void heapify (vector<int> &arr,int size) {
        for (int i=size/2;i>=0;i--) {
            if ((size-1)>= ((2*i)+1) && (arr[i]< arr[(2*i)+1])) {
                swap(arr[i], arr[(2*i)+1]);
            }
            
            if ((size-1)>= ((2*i)+2) && (arr[i]< arr[(2*i)+2])) {
                swap(arr[i], arr[(2*i)+2]);
            }
        }
    }
    
    /* swap the largest element which is at the beginning to the end element as
     * the largest element belongs to the end
     */
    void remove_heap(vector<int> &arr, int size) {
        swap(arr[0], arr[size-1]);
    }
    
    void heapsort(vector<int> &arr) {
        /* heap is a complete binary tree
         * so we will make use of the fact that
         * left child is a 2i+1 and right child is at
         * 2i+2 location
         */
        int size =static_cast<int>(arr.size());
        
        heapify(arr, size);
        while (size>1) {
            remove_heap(arr, size);
            size--;
            heapify(arr, size);
        }
    }
    
};

void test_heapsort (void);

#endif /* heapsort_h */
