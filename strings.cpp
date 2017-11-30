//
//  strings.cpp
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//
#include "common_incl.h"
#include "string.h"


void computelcs(vector<int> &lcs, string pattern)
{
    int len=0, i = 1;
    int size = static_cast<int>(pattern.length());
    lcs[0] = 0;
    
    while (i < size) {
        if (pattern[len] == pattern[i]) {
            len++;
            lcs[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lcs[len-1];
            } else {
                lcs[i]=0;
                i++;
            }
        }
    }
}

void kmp(string str, string pattern) {
    
    vector<int> lcs(pattern.length(),0);
    computelcs(lcs,pattern);
    
    int i=0, k=0;
    
    int text_length = static_cast<int>(str.length());
    int pattern_length = static_cast<int>(pattern.length());
    
    while (i<text_length) {
        
        if (str[i] == pattern[k]) {
            i++;
            k++;
        }
        
        if (k == pattern_length) {
            cout<< "pattern found at index " << i <<endl;
            k = lcs[k-1];
        } else if (i<text_length && str[i] != pattern [k]) {
            if (k != 0) {
                k = lcs[k-1];
            } else {
                i++;
            }
            
        }
    }
}

void swap (char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void permute (char *s, int start, int end)
{
    if (start == end) {
        cout << s<<endl;
        return;
    } else {
        for (int i=start; i<=end;i++) {
            swap(s+start,s+i);
            permute(s, start+1, end);
            swap(s+start,s+i);
        }
    }
}

void print_substr(char *str, int start, int end)
{
    for (int i=start; i<=end;i++) {
        cout<< str[i];
    }
    cout<<endl;
}

//
//long_pal_substring : this function finds the longest plaindromic substring in
//                     O(N^2) time with O(1) space. Idea is to find all the
//                     palindromes with even length and odd length for a given
//                     index and keep the longest one.
//
int long_pal_substring (char *str)
{
    int length = static_cast<int>(strlen(str));
    int maxLength = 1;
    
    int start = 0;
    int low = 0;
    int high = 1;
    for (int i=1; i<length; i++) {
        
        low = i-1;
        high = i;
        
        // consider even length palindromes with center a i so low is i-1 and high is i
        while(low>=0 && high < length && str[low]==str[high]) {
            //check for the maxlength so far
            if((high-low+1) > maxLength) {
                maxLength = high-low+1;
                start = low;
            }
            low--;
            high++;
        }
        
        low = i-1;
        high = i+1;
        
        // consider odd length palindromes with center a i so low is i-1 and high is i+1
        while(low>=0 && high < length && str[low]==str[high]) {
            //check for the maxlength so far
            if((high-low+1) > maxLength) {
                maxLength = high-low+1;
                start = low;
            }
            low--;
            high++;
        }
    }
    cout << "the longest palindromic string O(1) space is ";
    print_substr(str, start, start+maxLength-1);

    return maxLength;
}
//
//longest_palindromic_substring : DP solution which is O(N^2) and space also
//                                O(N^2)
//
int longest_palindromic_substring (char *str)
{
    int size = static_cast<int>(strlen(str));
    bool table[size][size];
    int max_length = 1;
    int start = 0;
    
    memset(table, false, sizeof(table));
    
    //all substring of length 1 is palindrome
    for (int i=0;i<size;i++) {
        table[i][i] = true;
    }
    
    //check for all substring of length 2
    for (int i=0;i<size-1;i++) {
        if (str[i] == str[i+1]) {
            table[i][i+1] = true;
            max_length = 2;
            //store the index of this substring
            start = i;
        }
    }
    
    //check for lenghts of greater than 2
    for (int k=3;k<size;k++) {
        // fix the starting index as we want to only
        // check for the substrings of length greater than 2
        for (int i=0;i<size-k+1;i++) {
            int j = i+k-1;
            if (table[i+1][j-1] && str[i] == str[j]) {
                table[i][j] = true;
                if (k>max_length) {
                    max_length = k;
                    start = i;
                }
            }
        }
    }
    cout << "the longest palindromic string is ";
    print_substr(str, start, start+max_length-1);
    return max_length;
}
void test_string (void) {
    kmp("ababababab", "aba");
    string a = "abc";
    char s [a.length()+1];
    strcpy(s, a.c_str());
    permute(s, 0, 2);
    char str[] = "forgeeksskeegfor";
    int max_pl_length = longest_palindromic_substring(str);
    cout<< "the longest palindromic substring is " << max_pl_length;
    cout<< endl;
    
    max_pl_length =  long_pal_substring(str);
    cout<<"the longest palindromic substring with O(1) space "<< max_pl_length;
    cout<<endl;
    
}
