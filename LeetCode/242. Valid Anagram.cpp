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
    
    //sorting takes O(nlogn) 
    //we can do O(n)  with map
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size()) return false;
        
        //map  char -> frequency
        unordered_map<char, int> umap;
        
        //step 1: use all chars frequency of string 's' in map
        for(char c:s) {
            umap[c]++;
        }
        
        //verify frequency with string 't'
        for(char c:t){
            umap[c]--; 
            if(umap[c]<0) return false;
        }
        
        return true; 
    }
};
