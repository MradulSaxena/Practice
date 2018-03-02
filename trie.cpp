//
//  trie.cpp
//  Practice
//
//  Created by Mradul Saxena on 10/25/17.
//  Copyright © 2017 Mradul Saxena. All rights reserved.
//


#include "trie.h"

trie_t * get_Node (void)
{
    trie_t * node = new trie_t;
    memset (node, 0, sizeof(trie_t));
    return node;
}

status_t search (trie_t *root, string word)
{
    int         size    = 0;
    trie_t      *crawl  = root;
    status_t    status  = EOK;
    
    if (!crawl) {
        return EPARAM;
    }
    
    size = static_cast<int>(word.length());
    for (int i=0; i<size; i++) {
        int index = word[i] - 'a';
        if (!crawl->children[index]) {
            cout<< "Not Found\n";
            return EOK;
        }
        
        crawl = crawl->children[index];
    }
    
    if (crawl->is_word) {
        cout<< word << " is present in the trie\n";
    } else {
        cout<< "Not Found\n";
    }
    
    return status;
    
}
status_t insert (trie_t *root, string word) {
    int         size    = 0;
    trie_t      *crawl  = root;
    status_t    status  = EOK;
    
    if (!crawl) {
        return EPARAM;
    }
    
    size = static_cast<int>(word.length());
    
    for (int i=0; i<size; i++) {
        int index = word[i] - 'a';
        if (!crawl->children[index]) {
            crawl->children[index] = get_Node();
        }
        crawl = crawl->children[index];
    }
    
    crawl->is_word = true;
    return status;
}

bool is_safe(int row_index, int col_index, vector<vector<bool>>visited, int max_row,
             int max_column)
{
    if (row_index>=0 && row_index<max_row && col_index >=0 &&
        col_index<max_column && !visited[row_index][col_index]) {
        return true;
    }
    
    return false;
}
void find_word(vector<vector<char>> input_matrix, vector<vector<bool>> &visited,
               trie_t *root, string str, int row_index, int col_index)
{
    if (root->is_word) {
        cout<< str<<endl;
        return;
    }
    
    if (is_safe(row_index, col_index, visited, static_cast<int>(input_matrix.size()),
                static_cast<int>(input_matrix[0].size()))) {
        visited[row_index][col_index] = true;
        
        for (int i=0; i< 26; i++) {
            if (root->children[i]) {
                find_word(input_matrix, visited, root->children[i], str, row_index+1, col_index+1);
                find_word(input_matrix, visited, root->children[i], str, row_index+1, col_index);
                find_word(input_matrix, visited, root->children[i], str, row_index, col_index+1);
                find_word(input_matrix, visited, root->children[i], str, row_index-1, col_index-1);
                find_word(input_matrix, visited, root->children[i], str, row_index-1, col_index);
                find_word(input_matrix, visited, root->children[i], str, row_index, col_index-1);
                find_word(input_matrix, visited, root->children[i], str, row_index-1, col_index+1);
                find_word(input_matrix, visited, root->children[i], str, row_index+1, col_index-1);
            }
        }
    }
}
void find_words (trie_t *root, vector<vector<char>> input_matrix)
{
    int row = static_cast<int>(input_matrix.size());
    if (row == 0) {
        return;
    }
    
    int column = static_cast<int>(input_matrix[0].size());
    cout << "row is " << row;
    cout << "\n col is " <<column <<endl;
    for (int i=0;i<row;i++) {
        string str;
        for (int j=0;j<column;j++) {
            vector<vector<bool>> visited(row,vector<bool>(column, false));
            if (root->children[j]) {
                str += input_matrix[i][j];
                find_word(input_matrix, visited, root->children[j], str, i, j);
                str = "";
            }
        }
        
    }
}
//
//
//
void test_trie (void)
{
    status_t status = EOK;
    vector<string> keys = { "the", "a", "there",
                            "answer", "any", "by",
                            "bye", "their" };
    trie_t *root = get_Node();

    for (string i:keys) {
        status = insert(root, i);
        if (status != EOK) {
            cout << "Trie insert failed for key " << i;
        }
    }
    
    string word = "a";
    status = search(root, word);
    if (status != EOK) {
        cout << "search for word " << word << " failed\n";
    }
    
    vector<string> boggle_keys = {"geeks", "for", "quiz", "gee"};
    trie_t *boggle_root = get_Node();
    
    for (string i:boggle_keys) {
        status = insert(boggle_root, i);
        if (status != EOK) {
            cout << "Trie insert failed for key " << i;
        }
    }

    vector<vector<char>> boggle_matrix = {{'G','I','Z'},
                                          {'U','E','K'},
                                          {'Q','S','E'}
                                         };
    
    find_words(boggle_root, boggle_matrix);
    
}
