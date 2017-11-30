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

//
//swap: utility function to swap two characters
//
void swap (char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

//
//permute: this function prints all the permutation for a given string
//
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

//
//check_parentheses: this function checks for the balanced parantheses in a given
//                   string
//

bool check_parentheses(string str)
{
    stack<char> my_stack;
    
    for (int i=0; i<str.length();i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            my_stack.push(str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            char temp = my_stack.top();
            my_stack.pop();
            
            if (str[i] == ')') {
                if (temp != '(') {
                    return false;
                }
            }
            if (str[i] == '}') {
                if (temp != '{') {
                    return false;
                }
            }
            
            if (str[i] == ']') {
                if (temp != '[') {
                    return false;
                }
            }
        }
    }
    
    if (!my_stack.empty()) {
        return false;
    }
    
    return true;
}

//
//print_substr: utility function to print the substring for a string
//
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

//
//reverse : utility function to reverse a word in the string
//
void reverse (string &str, int start, int end)
{
    while(start<end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

//
//reversewords: this function reverses a given string
//
void reversewords (string &str)
{
    char temp;
    int start = 0;
    for (int i=0;i<=str.length();i++) {
        if (i == str.length()) {
            reverse(str, start, i-1);
        } else {
            temp = str[i];
            if (temp == ' ') {
                reverse(str, start, i-1);
                start = i+1;
            }
        }
    }
    reverse(str, 0, static_cast<int>(str.length()-1));
    cout<< str;
}

// recursive equation
//int lcs( char *X, char *Y, int m, int n )
//{
//    if (m == 0 || n == 0)
//        return 0;
//    if (X[m-1] == Y[n-1])
//        return 1 + lcs(X, Y, m-1, n-1);
//    else
//        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
//}
//
//LCSubsequence: DP solution for LCS
//
int LCSubsequence (string str1, string str2)
{
    int len1 = static_cast<int>(str1.length());
    int len2 = static_cast<int>(str2.length());
    int table[len1+1][len2+1];
    int result = 0;
    
    for (int i=0;i<=len1;i++) {
        for (int j=0;j<=len2;j++) {
            // Create a table to store lengths of longest common suffixes of
            // substrings.   Notethat table[i][j] contains length of longest
            // common suffix of X[0..i-1] and Y[0..j-1]. The first row and
            // first column entries have no logical meaning, they are used only
            // for simplicity of program
            if (i==0 || j==0) {
                table[i][j] = 0;
            } else if (str1[i-1] == str2[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
                result = max(result, table[i][j]);
            } else {
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }
    return table[len1][len2];
}
//The longest common suffix has following optimal substructure property
//LCSuff(X, Y, m, n) = LCSuff(X, Y, m-1, n-1) + 1 if X[m-1] = Y[n-1]
//                     0  Otherwise (if X[m-1] != Y[n-1])
//
//The maximum length Longest Common Suffix is the longest common substring.
//LCSubStr(X, Y, m, n)  = Max(LCSuff(X, Y, i, j)) where 1 <= i <= m
//                        and 1 <= j <= n
int LCSubstr (string str1, string str2)
{
    int len1 = static_cast<int>(str1.length());
    int len2 = static_cast<int>(str2.length());
    int table[len1+1][len2+1];
    int result = 0;
    
    for (int i=0;i<=len1;i++) {
        for (int j=0;j<=len2;j++) {
            // Create a table to store lengths of longest common suffixes of
            // substrings.   Notethat table[i][j] contains length of longest
            // common suffix of X[0..i-1] and Y[0..j-1]. The first row and
            // first column entries have no logical meaning, they are used only
            // for simplicity of program
            if (i==0 || j==0) {
                table[i][j] = 0;
            } else if (str1[i-1] == str2[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
                result = max(result, table[i][j]);
            } else {
                table[i][j] = 0;
            }
        }
    }
    return result;
}
void test_string (void) {
    kmp("ababababab", "aba");
    
    cout<<"\nPrint all the permutations of a string\n";
    char s[] = "ABCD";
    permute(s, 0, static_cast<int>(strlen(s)-1));
    cout<<endl;
    
    char str[] = "forgeeksskeegfor";
    int max_pl_length = longest_palindromic_substring(str);
    cout<< "the longest palindromic substring is " << max_pl_length;
    cout<< endl;
    
    max_pl_length =  long_pal_substring(str);
    cout<<"the longest palindromic substring with O(1) space "<< max_pl_length;
    cout<<endl;
    
    cout<<"\nParentheses Checker\n";
    cout << "The parentheses are balanced "<<check_parentheses("(a(b{c+d}))");
    cout<<endl;
    
    cout<<"\nReverse Words\n";
    string str1 = "i like programming very much";
    reversewords(str1);
    cout<<endl;
    
    cout<<"\nLongest Common Substring\n";
    string st1 = "GeeksforGeeks";
    string st2 = "GeeksQuiz";
    cout<<"the longest common substring is " << LCSubstr(st1, st2);
    cout<<endl;
    
    cout<<"\nLongest Common Subsequence\n";
    string st3 = "AGGTAB";
    string st4 = "GXTXAYB";
    cout<<"the longest common subsequence is " << LCSubsequence(st3, st4);
    cout<<endl;
}
