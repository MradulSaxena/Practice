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


void test_string (void) {
    kmp("ababababab", "aba");
}
