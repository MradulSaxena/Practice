//
//  array.cpp
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#include "common_incl.h"
#include "array.h"


int findone(const vector<int> a)
{
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

//
// Kadane's Algorithm is also known as maximum subarray
//
int kadane_algorithm (vector <int>&arr)
{
    int max_ending_here = 0;
    int max_so_far = 0;
    
    for (int i=0;i<arr.size();i++) {
        
        max_ending_here += arr[i];
        
        if (max_ending_here < 0) {
            max_ending_here = 0;
        }
        
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
    }
    
    return max_so_far;
}


//
// find a missing number from a sorted array
//
int findmissing(vector<int>&arr, int start, int high, const int first_val)
{
    
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
// Subarray with given sum (Google, Facebook, Apple, Amazon)
//
void subarray_with_given_sum (vector<int>&arr, int sum)
{
    int index_low = 0;
    int index_high = 0;
    int curr_sum = 0;
    
    while (curr_sum != sum && index_high<arr.size()) {
        //
        // repeatedly subtract the lower number index until curr_sum <= sum
        //
        while (curr_sum > sum && index_low <arr.size()) {
            curr_sum = curr_sum - arr[index_low];
            index_low++;
        }
        
        curr_sum += arr[index_high];
        index_high++;
    }
    
    cout << "\nSubarray found at " <<index_low<< " "<< index_high-1 <<endl;
}

//
// Sort an array of 0s 1s and 2s
//
void sort_array_0_1_2 (vector<int> &arr)
{
    
    int zero_count = 0;
    int ones_count = 0;
    int twos_count = 0;
    
    for (int i : arr) {
        if (i == 0) {
            zero_count++;
        } else if (i == 1) {
            ones_count++;
        } else {
            twos_count++;
        }
    }
    
    for (int i = 0;i<arr.size();i++) {
        if (zero_count != 0) {
            arr[i] = 0;
            zero_count--;
        } else if (ones_count != 0) {
            arr[i]  = 1;
            ones_count--;
        } else {
            arr[i]  = 2;
            twos_count--;
        }
    }
}

//
// find the point where left sum is equal to the right sum
// idea is to keep track of right sum and left sum at each index
//
void find_equilibrium_point (const vector<int> arr)
{
    int array_size = static_cast<int>(arr.size());
    int sum = 0;
    
    for (int i:arr) {
        sum+=i;
    }
    
    int left_sum = 0;
    
    for (int i=0;i<array_size;i++) {
        // This holds the right sum for ith index
        sum = sum - arr[i];
        
        if (left_sum == sum) {
            cout << "Solution found at " << i <<endl;
            return;
        }
        
        left_sum += arr[i];
    }
}

//
//  max_increasing_subsequence : find the maximum sum from increasing numbers
//
int max_increasing_subsequence (const vector<int> arr)
{
    
    int size = static_cast<int>(arr.size());
    
    vector<int>dp;
    
    for (int i:arr) {
        dp.push_back(i);
    }
    
    for (int i =1; i<size; i++) {
        for (int j=0; j<i; j++) {
            if (arr[i] > arr[j]) {
                if (dp[i] < (dp[j] + arr[i])) {
                    dp[i] = dp[j] + arr[i];
                }
            }
        }
    }
    
    int max = INT_MIN;
    for (int i =0;i<size;i++) {
        if (max<dp[i]) {
            max = dp[i];
        }
    }
    return max;
}


//
//  LIS : find the longest increasing subsequence
//
int LIS (const vector<int> arr)
{
    
    int size = static_cast<int>(arr.size());
    
    vector<int>dp(size, 1);
    
    for (int i =1; i<size; i++) {
        for (int j=0; j<i; j++) {
            if (arr[i] > arr[j]) {
                if (dp[i] < (dp[j] +1)) {
                    dp[i] = dp[j] +1;
                }
            }
        }
    }
    int max = INT_MIN;
    for (int i =0;i<size;i++) {
        if (max<dp[i]) {
            max = dp[i];
        }
    }
    return max;
}

//
//leaders : print all the leaders in the array. right most element is always
//          leader. element greater than all it right neighbor is a leader.
//
void leaders (const vector <int> arr) {
    int size = static_cast<int>(arr.size());
    
    if (size == 0) {
        return;
    }
    
    int max = arr[size-1];
    // right most is always the leader
    cout << max;
    
    for (int i = size-2; i>=0; i--) {
        if (arr[i] > max) {
            cout << " "<< arr[i];
            max = arr[i];
        }
    }
}
//
//minimum_platforms : find the minimum number of platforms needed for trains
//                    given their arrival and departure times.
//
int minimum_platforms (vector<int> arrival_times,
                       vector<int> departure_times)
{
    //algorithm is to sort both and then check how many of them overlap
    int min_platforms_needed = 0;
    sort(arrival_times.begin(), arrival_times.end());
    sort(departure_times.begin(), departure_times.end());
    
    int size =static_cast<int>(arrival_times.size());
    int result = 0;
    int arrival=0;
    int departure=0;
    
    while (arrival<size && departure<size) {
        if (arrival_times[arrival]<departure_times[departure]) {
            min_platforms_needed++;
            arrival++;
            
            if (min_platforms_needed>result) {
                result = min_platforms_needed;
            }
        } else {
            min_platforms_needed--;
            departure++;
        }
    }
    
    return result;
}
void test_array (void) {

    vector<int> arr = {4,5,6,7,8,10,11,12};
    //vector<int> arr = {1,2,3,4,6,7,8,9};
    cout << "val is "<<
    findmissing(arr, 0, static_cast<int>(arr.size()-1), arr[0])<< endl;
    
    cout << "\nFind the number appearing only once in the array\n";
    vector<int>array1 = {1,1,1,2,2,3,2,3,3,5};
    cout<< "number is "<< findone(array1)<<endl;
    
    cout << "\nFind the maximum subarray (Kadane Algorithm)\n";
    vector<int> array2 = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "maximum_subarray sum is " << kadane_algorithm(array2)<<endl;
    
    cout << "\nFind the subarray with the given sum\n";
    vector<int> array3 = {15, 2, 4, 8, 9, 5, 10, 23};
    subarray_with_given_sum(array3, 23);
    
    cout << "\nSort an array of 0s 1s and 2s\n";
    vector<int>array4 = {1,2,1,0,2,1,0,2,0,1};
    sort_array_0_1_2(array4);
    
    for (int i: array4) {
        cout << i << " ";
    }
    cout << endl;
    
    cout << "\nEquilibrium Point (Sum of left = Sum of right)\n";
    vector<int> equili = {-7, 1, 5, 2, -4, 3, 0};
    find_equilibrium_point(equili);
    cout << endl;
    
    cout << "\nMaximum Sum Increasing Subsequence(Not LIS) \n";
    cout << "Maximum Sum Increasing Subsequence is " <<
            max_increasing_subsequence(array3);
    cout << endl;
    
    cout << "\nLongest Increasing Subsequence \n";
    cout << "LIS is " << LIS(array3);
    cout << endl;
    
    vector<int> leader_array = {16, 17, 4, 3, 5, 2};
    cout << "\nLeaders in array \n";
    cout << "Leaders in the array {16, 17, 4, 3, 5, 2} are ";
    leaders(leader_array);
    cout << endl;
    
    vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};
    cout << "\nMinimum Platforms\n";
    cout << "Minimum Platforms required for trains are " <<
            minimum_platforms(arrival, departure);
    cout << endl;

}
