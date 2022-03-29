/*
Given two strings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
*/

class Solution {
public:
    //insert magazine into set; traverse ransom note and verify if it exist in set
    bool canConstruct(string ransomNote, string magazine) {
        
        if(ransomNote.empty() && magazine.empty()) return true;
        if(magazine.empty()) return false;
        
        unordered_multiset<char> lset;
        for(auto c:magazine){
            lset.emplace(c);            
        }
        
        for(auto c:ransomNote){
            unordered_multiset<char> ::iterator itr = lset.find(c);
            if(itr == lset.end()){
                return false;
            }
            lset.erase(itr);
        }
        return true;        
    }
};
