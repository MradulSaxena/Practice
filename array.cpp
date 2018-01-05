//
//  array.cpp
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//

#include "common_incl.h"
#include "array.h"

//
// Find the number appearing once in the array
//
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
    
    for (int i: arr) {
        cout << i << " ";
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
//  LIS : find the longest increasing subsequence
//  Algorithm: DP solution. Keep a memoized array to store the LIS till i-1 and use
//             that to find the LIS of i. idea is to increment LIS of i if a[i]
//             > a[j] and LIS [i] < LIS[j]+1. Do this for j=0 to i-1.
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
//  max_increasing_subsequence : find the maximum sum from increasing numbers
//  Algorithm: DP Solution. Same as LIS. instead of adding 1 to the result we
//             add arr[i] and use arr[i] to check if we need to update the dp[i]
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
//Algorithm:          sort both the array in increasing order, keep two variables
//                    and increment platform if they overlap and decrement if they
//                    don't.keep track of the max platforms ever seen.
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

//
//find_k_smallest: Find the kth smallest element from the given array
//Algorithm: create a min heap (priority Q) from the array, then pop min k times
//
int find_k_smallest (const vector<int> arr, int k)
{
    priority_queue<int, vector<int>, compare> pq;
    
    for (int i:arr) {
        pq.push(i);
    }
    
    while (k>0) {
        pq.pop();
        k--;
    }
    
    return pq.top();
}

//
//get_max: utility function to get the max out of a Queue DS
//
int get_max (const deque<int> queue) {
    
    int max = INT_MIN;
    
    for (int i : queue) {
        if (max<i) {
            max = i;
        }
    }
    
    return max;
}

//
// Maximum of all subarrays of size k
// Algorithm: create a queue of size k and find the max, then keep on
//            popping from the back and push to the front
//
void max_k_subarray (const vector<int> arr, int k)
{
    deque<int> queue;
    int size = static_cast<int>(arr.size());
    
    for (int i=0; i<=size; i++) {
        if (queue.size() == k) {
            cout << get_max(queue) << " ";
            queue.pop_back();
        }
        if (i<size)
            queue.push_front(arr[i]);
    }
}

//
// Trapping Rain Water: find the amount of water that can be stored between ,
//                      given the height of the bars
// Algorithm: Precompute. We keep track of the max left height for each cell as
//            well as the right height. The amount of water that it can hold is
//            the smaller of the two heights minus the height of the cell.
//            Do this for all the cells and add the result. O(n)
//
int find_capacity (const vector<int> arr)
{
    int size = static_cast<int>(arr.size());
    
    if (size < 2) {
        //cannot store water
        return 0;
    }
    
    vector<int> left(size, 0);
    vector<int> right(size, 0);
    int stored_water = 0;
    
    // precompute left array
    left[0] = arr[0];
    for (int i=1; i<size; i++) {
        left[i] = max(left[i-1],arr[i]);
    }
    
    //precompute right array
    right[size-1] = arr[size-1];
    for (int i=size-2; i>=0; i--) {
        right[i] = max(right[i+1],arr[i]);
    }
    
    // Calculate the accumulated water for each element
    // consider the amount of water on ith bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i]
    for (int i=0; i<size; i++) {
        stored_water += min(left[i], right[i]) - arr[i];
    }
    
    return stored_water;
}

//
// find_triplets : Pythagorean Triplet in an array
//                 find if there exist a triplet in the array such that
//                 a^2 + b^2 = c^2
// Algorithm:      We store all the psossible a^2 + b^2 in a set so that they
//                 are unique and then check the square of every number. If it
//                 exist in the set then there is a solution.
//                 PS: This solution will only work if array has all non-zero
//                     values
//
bool find_triplets (const vector<int> arr) {
    
    int size = static_cast<int>(arr.size());
    unordered_set<int> my_set;
    
    for (int i=0; i < size; i++) {
        for (int j=0; j < size;j++) {
            if (i==j) continue;
            my_set.insert(pow(arr[i],2) + pow(arr[j],2));
        }
    }
    
    for (int i=0; i<size; i++) {
        int value = pow(arr[i],2);
        if (my_set.count(value)) {
            return true;
        }
    }
    return false;
}

typedef struct Interval {
    int buy;
    int sell;
}Interval_t;
//
//stockBuySell : Maximize the profit given the price of stock at each day
//
void stockBuySell (const vector<int> stock_prices)
{
    int size =  static_cast<int>(stock_prices.size());
    vector<Interval_t> sol;
    
    if (size == 1) {
        return;
    }
    
    int i=0;
    
    while (i<size-1) {
        Interval_t temp;
        //Find the local minima first
        while (i<size-1 && stock_prices[i+1]<stock_prices[i]) {
            i++;
        }
        
        temp.buy = stock_prices[i++];
        
        //Find the local maxima
        while(i<size-1 && stock_prices[i+1]>stock_prices[i]) {
            i++;
        }
        temp.sell = stock_prices[i];
        sol.push_back(temp);
    }
    
    for (int i=0;i<sol.size();i++) {
        cout<<"BUY: " <<sol[i].buy;
        cout<<" SELL: " <<sol[i].sell;
        
        cout<<endl;
    }
}

//
//min_jump : find the minimum number of jumps needed to reach the end
//
int min_jump (const vector<int> jump)
{
    int size  = static_cast<int>(jump.size());
    
    vector<int> jumps(size, INT_MAX);
    
    if (size == 0 || jump[0] == 0) {
        return INT_MAX;
    }
    
    jumps[0] = 0;
    for (int i=1;i<size;i++) {
        for (int j=0;j<i;j++) {
            if (i <= j+jump[j] && jump[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j]+1);
            }
        }
    }
    
    return jumps[size-1];
}

//
//print_jumping_numbers: prints the jumping numbers less than the given x
//
void print_jumping_numbers (int x, int num)
{
    
    queue<int> qu;
    qu.push(num);
    
    while(!qu.empty()) {
        num = qu.front();
        qu.pop();
        if (num <= x) {
            cout << num<< " ";
            int digit = num %10;
            
            if (digit==0) {
                qu.push((10*num) + (digit+1));
            } else if (digit == 9) {
                qu.push((10*num) + (digit-1));
            } else {
                qu.push((10*num) + (digit+1));
                qu.push((10*num) + (digit-1));
            }
        }
    }
    
    return;
}

int reverse_number (int x) {
    
    int result = 0;
    int temp = x;
    while(x) {
        int remainder = x%10;
        result = result*10 + remainder;
        x = x/10;
    }
    return temp>0?result:-result;
}


vector<vector<int>> find_3sum_triplets (vector<int> nums)
{
    vector<vector<int>> sol = {};
    
    // sort the input
    sort(nums.begin(), nums.end());

    for (int i=0;i<nums.size()-2;i++) {
        int l = i+1;
        int r = static_cast<int>(nums.size())-1;
        int num = nums[i];
        while(l<r) {
            if ((nums[l] + nums[r] + nums[i]) > 0) {
                r--;
            } else if ((nums[l] + nums[r] + nums[i]) < 0) {
                l++;
            } else {
                vector<int> temp;
                temp.push_back(num);
                temp.push_back(nums[l]);
                temp.push_back(nums[r]);
                sol.push_back(temp);
                int temp1 = nums[l];
                int temp2 = nums[r];
                while(l<r && nums[l] == temp1) l++;
                while(l<r && nums[r] == temp2) r--;
            }
        }

        while ((i<(static_cast<int>(nums.size()) - 2)) && (nums[i] == nums[i+1])) i++;
    }
    
    return sol;
}

//
//job_scheduling_with_cooldown: schedule jobs with the given cooldown such that
//                              no two same jobs can be scheduled before cooldown
//
vector<string>
job_scheduling_with_cooldown (vector<int>tasks, int cooldown)
{
    vector<string> sol;
    unordered_map<int, int> my_map;
    
    for (int i=0; i<tasks.size();i++) {
        if (my_map.count(tasks[i])) {
            int last_time = my_map[tasks[i]];
            if ((i-last_time)>cooldown) {
                sol.push_back(to_string(tasks[i]));
            } else {
                int diff = i-last_time;
                while(diff <= cooldown) {
                    sol.push_back("_");
                    diff++;
                }
                sol.push_back(to_string(tasks[i]));
            }
            my_map[tasks[i]] = i;
        } else {
            my_map.insert(make_pair(tasks[i], i));
            sol.push_back(to_string(tasks[i]));
        }
    }
    
    return sol;
}


// Driver function to sort the vector elements
// by first element of pairs
bool cmp (const pair<int,int> &a,
          const pair<int,int> &b)
{
    return (a.first < b.first);
}

//
// russian_doll_envelope : You have a number of envelopes with widths and heights
//                         given as a pair of integers (w, h). One envelope can
//                         fit into another if and only if both the width and
//                         height of one envelope is greater than the width and
//                         height of the other envelope.
//                         What is the maximum number of envelopes can you
//                         Russian doll? (put one inside other)
//
int russian_doll_envelope (vector<pair<int, int>> envelopes)
{
    int result = 0;
    int size = static_cast<int>(envelopes.size());
    
    vector<int> dp(size, 1);

    sort(envelopes.begin(), envelopes.end(), cmp);

    if (size==0) {
        return result;
    }

    for (int i=0; i<size; i++) {

        pair<int,int> temp = envelopes[i];

        for (int j=0;j<i;j++) {

            pair<int,int> temp_next = envelopes[j];

            if (temp.first > temp_next.first &&
                temp.second > temp_next.second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        result = max(result, dp[i]);
    }
    return result;
}

//
//is_valid_placement for the queens
//
bool is_valid_placement(vector<int> &col)
{
    int row_id = static_cast<int>(col.size()) - 1;
    
    for (int i=0;i<row_id;i++) {
        int diff = abs (col[i] - col[row_id]);
        if ((diff == 0) || (diff == row_id-i)) {
            // diff == 0 means same column
            // diff == row-i means diagonally same
            return false;
        }
        
    }
    return true;
}

void solve_NQueens (int n, int row, vector<int> &col, vector<vector<int>> &result)
{
    if (n == row) {
        result.push_back(col);
    } else {
        for (int i=0; i<n; i++) {
            col.push_back(i);
            if (is_valid_placement(col)) {
                solve_NQueens(n,row+1, col, result);
            }
            col.pop_back();
        }
    }
}

//
//n_queens: N Queens Problem
//
vector<vector<int>> n_queens(int row)
{
    vector<vector<int>> sol;
    vector<int> col;
    
    solve_NQueens(row, 0, col, sol);
    
    return sol;
    
}

//
//generate_permutations: Generate permutations for the given input
//                       Idea is to go over all the possibities with recursion
//                       and a for loop
//
void generate_permutations(vector<int> arr, int start)
{
    if (start == arr.size()-1) {
        for (auto i:arr) {
            cout<< i << " ";
        }
        cout <<endl;
    }
    
    for (int i=start;i<arr.size();i++) {
        swap(arr[start], arr[i]);
        generate_permutations(arr, start+1);
        swap(arr[start], arr[i]);
    }
    
}

//
//generate_power_set : Generate power set for the given set
//
void generate_power_set(vector<int> arr, int to_be_selected, vector<int> &temp_select,
                        vector<vector<int>> &power_set)
{
    if (to_be_selected == arr.size()) {
        power_set.push_back(temp_select);
        return;
    }
    
    temp_select.push_back(arr[to_be_selected]);
    generate_power_set(arr, to_be_selected+1, temp_select, power_set);
    temp_select.pop_back();
    generate_power_set(arr, to_be_selected+1, temp_select, power_set);
}

//
//generateGrayarr : compute gray code for the given number of digits
//                  idea is to append 0 to the array and append 1 to the
//                  reverse of the given array and then append both to get the
//                  result.
//
void generateGrayarr(int n)
{
    vector<string> temp;
    if (n<=0) {
        return;
    }
    temp.push_back("0");
    temp.push_back("1");
    
    for (int i= 2; i<(1<<n); i = (i<<1))
    {
        //reverse temp and assign to prefix_1 and prepend 1 to it
        for (int j=i-1;j>=0;j--) {
            temp.push_back(temp[j]);
        }
        
        for (int j=0;j<i;j++) {
            temp[j] = "0"+temp[j];
        }
        
        for (int j=i;j<2*i;j++) {
            temp[j] = "1"+temp[j];
        }
    }
    
    for (auto i:temp) {
        cout<<i<<endl;
    }
    
}

void test_array (void) {

    cout << "\nFind the missing number from the sorted array\n";
    vector<int> arr = {4,5,6,7,8,10,11,12};
    //vector<int> arr = {1,2,3,4,6,7,8,9};
    cout << "the missing number from aray {4,5,6,7,8,10,11,12} is "<<
    findmissing(arr, 0, static_cast<int>(arr.size()-1), arr[0]);
    cout << endl;
    
    cout << "\nFind the number appearing only once in the array "
            "{1,1,1,2,2,3,2,3,3,5} \n";
    vector<int>array1 = {1,1,1,2,2,3,2,3,3,5};
    cout << "the number appearing once is "<< findone(array1);
    cout << endl;
    
    cout << "\nFind the maximum subarray (Kadane Algorithm)\n";
    vector<int> array2 = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "maximum_subarray sum is " << kadane_algorithm(array2);
    cout << endl;
    
    cout << "\nFind the subarray with the given sum\n";
    vector<int> array3 = {15, 2, 4, 8, 9, 5, 10, 23};
    subarray_with_given_sum(array3, 23);
    cout << endl;
    
    cout << "\nSort an array of 0s 1s and 2s\n";
    vector<int>array4 = {1,2,1,0,2,1,0,2,0,1};
    sort_array_0_1_2(array4);
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

    int k = 5;
    cout << "\nKth Smallest Number in an array\n";
    cout << "Kth smallest number of array {15, 2, 4, 8, 9, 5, 10, 23} "
            "where k is " << k << " is " << find_k_smallest(array3, k);
    cout << endl;
    
    cout << "\nMaximum of all subarrays of size k (sliding window max)\n";
    cout << "Maximum of all subarrays of array {15, 2, 4, 8, 9, 5, 10, 23} "
            "size k where k is 4 is ";
    max_k_subarray(array3, k);
    cout << endl;
    
    cout << "\nTrapping Rain Water\n";
    vector<int> rain_water_vector = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Maximum rain water that can be accumulated is " <<
            find_capacity(rain_water_vector);
    cout << endl;
    
    cout << "\nPythagorean Triplets\n";
    vector<int> pytha_triplet = {3, 1, 4, 6, 5};
//    vector<int> pytha_triplet = {10, 4, 6, 12, 5};
    cout << "Pythagorean Triplet exist in the array " <<
    find_triplets(pytha_triplet);
    cout << endl;
    
    cout<< "\nBuy and Sell Stocks\n";
    vector<int> stock_prices = {100, 180, 260, 310, 40, 535, 695};
    stockBuySell(stock_prices);
    cout << endl;
    
    cout<< "\nmin jumps\n";
    vector<int> jump = {1, 3, 6, 1, 0, 9};
    cout<< "minimum number of jumps needed are " << min_jump(jump);
    cout<<endl;
    
    cout<<"\njumping numbers\n";
    int x=40;
    for (int i=1; i<=9 && i<=x; i++)
        print_jumping_numbers(x, i);
    cout<<endl;
    
    cout<<"\nN-Queens Problem\n";
    // size of the board
    int n = 4;
    vector<vector<int>> sol_queens = n_queens(n);
    for (int i=0; i<sol_queens.size();i++) {
        for (int j=0;j<sol_queens[0].size();j++) {
            cout << sol_queens[i][j] << " , ";
        }
        cout << endl;
    }
    cout<<endl;
    
    cout<<"\nReverse Number\n";
    cout << reverse_number(4245);
    cout<<endl;
    
    cout<<"\nFind all unique triplets with zero sum\n";
    vector<int> three_sum = {0, -1, 2, -3, 1};
    vector<vector<int>> sol;
    sol = find_3sum_triplets(three_sum);
    for (int i=0; i<sol.size();i++) {
        for (int j=0;j<3;j++) {
            cout << sol[i][j] << " , ";
        }
        cout << endl;
    }
    cout<<endl;
    
    vector<int> tasks = {1, 2, 1, 1, 3, 4};
    int cooldown = 2;
    vector<string> task_res;
    cout<<"\nJob Scheduling with Cool Down\n";
    task_res = job_scheduling_with_cooldown(tasks, cooldown);
    
    for(auto i:task_res) {
        cout<< i<< ",";
    }
    cout<<endl;
    
//    find_celebrity();
    
    cout<<"\nRussian Doll Envelope Problem\n";
    vector<pair<int, int>> envelope;
    envelope.push_back(make_pair(5,4));
    envelope.push_back(make_pair(6,4));
    envelope.push_back(make_pair(6,7));
    envelope.push_back(make_pair(2,3));
    cout<<russian_doll_envelope(envelope);
    cout<<endl;
    
    cout<<"\nGenerate Permutations\n";
    vector<int>permute = {1,2,3,4};
    generate_permutations(permute, 0);
    cout<<endl;
    
    cout<<"\nPower Set\n";
    vector<vector<int>> power_set = {};
    vector<int> last_sol = {};
    generate_power_set(permute, 0, last_sol, power_set);
    for (int i=0; i<power_set.size();i++) {
        vector<int>temp = power_set[i];
        cout << "{";
        for (int j=0;j<temp.size();j++) {
            cout << temp[j] << "  ";
        }
        cout << "}"<<endl;
    }
    
    cout<<endl;
    
    cout<<"\nGray Code\n";
    generateGrayarr(3);
    cout<<endl;
    
}
