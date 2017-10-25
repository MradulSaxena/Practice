//
//  quicksort.h
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#ifndef quicksort_h
#define quicksort_h

class quickSort {
    
public:
    void swap (int &a, int &b) {
        a = a+b;
        b = a-b;
        a = a-b;
    }
    int partition(vector<int> &arr, int start, int size) {
        int i = start-1;
        int pivot = arr[size];
        for (int j=start; j<=size-1; j++) {
            if (arr[j]<=pivot) {
                i++;
                //swap(arr[i],arr[j]);
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        //swap(arr[i+1], arr[size]);
        int temp = arr[i+1];
        arr[i+1] = arr[size];
        arr[size] = temp;
        return i+1;
    }
    
    void quicksort (vector<int> &arr, int start, int size) {
        if (start> size) {
            return;
        }
        
        int pivot = partition(arr,start,size);
        quicksort(arr,start, pivot-1);
        quicksort(arr, pivot+1, size);
    }
};

void test_quicksort (void);
#endif /* quicksort_h */
