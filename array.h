//
//  array.h
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#ifndef array_h
#define array_h

//
//comparator function to pass to the stl
//
struct compare {
    bool operator() (const int &a, const int &b) {
        return a > b ? true: false;
    }
};

//
//comparator function to pass to the stl
//
struct greater_comp {
    bool operator() (const int &a, const int &b) {
        return a < b ? true: false;
    }
};

void test_array(void);


int findone(const vector<int> a);
//
// find a missing number from a sorted array
//
int findmissing(vector<int>&arr, int start, int high,const int first_val);

//
// Kadane's Algorithm is also known as maximum subarray
//
int kadane_algorithm (vector <int>&arr);

//
// Subarray with given sum (Google, Facebook, Apple, Amazon)
//
void subarray_with_given_sum (vector<int>&arr, int sum);

//
// Sort an array of 0s 1s and 2s
//
void sort_array_0_1_2 (vector<int> &arr);

//
// find the point where left sum is equal to the right sum
// idea is to keep track of right sum and left sum at each index
//
void find_equilibrium_point (vector<int> arr);

//
//  max_increasing_subsequence : find the maximum sum from increasing numbers
//
int max_increasing_subsequence (vector<int> arr);

//
//  LIS : find the longest increasing subsequence
//
int LIS (vector<int> arr);

//
//leaders : print all the leaders in the array. right most element is always
//          leader. element greater than all it right neighbor is a leader.
//
void leaders (vector <int> arr);
//
//minimum_platforms : find the minimum number of platforms needed for trains
//                    given their arrival and departure times.
//
int minimum_platforms (const vector<int> arrival_times,
                       const vector<int> departure_times);

//
//find_k_smallest: Find the kth smallest element from the given array
//
int find_k_smallest (const vector<int> arr, int k);

//
//Maximum of all subarrays of size k
//
void max_k_subarray (const vector<int> arr, int k);

//
// Trapping Rain Water: find the amount of water that can be stored between ,
//                      given the height of the bars
// Algorithm: Precompute. We keep track of the max left height for each cell as
//            well as the right height. The amount of water that it can hold is
//            the smaller of the two heights minus the height of the cell.
//            Do this for all the cells and add the result. O(n)
//
int find_capacity (const vector<int> arr);

//
//find_triplets : Pythagorean Triplet in an array
//                find if there exist a triplet in the array such that
//                a^2 + b^2 = c^2
//
bool find_triplets (const vector<int> arr);
#endif /* array_h */
