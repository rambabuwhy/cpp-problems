/*

Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
        return false;
        
        unordered_map<char, int> umap;
        
        for(char c:s){
            umap[c]++;
        }
        
        for(char c:t){
            
            umap[c]--;
            
            if(umap[c]<0)
            return false;
        }
        
        return true;
        
    }
};
