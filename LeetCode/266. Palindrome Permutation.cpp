/*
Given a string, determine if a permutation of the string could form a palindrome.

Example 1:

Input: "code"
Output: false
Example 2:

Input: "aab"
Output: true
Example 3:

Input: "carerac"
Output: true

*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        
        unordered_map<char,int> umap;
        
        for(int i =0; i<s.size(); i++){
            umap[s[i]]++;
        }
        
        int count = 0;
        
        for(int i =0; i<umap.size(); i++)
        count = count + (umap[i] % 2);
        
        
        
        return count <= 1;
        
    }
};
