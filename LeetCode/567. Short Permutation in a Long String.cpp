/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s2.size() < s1.size()) return false;
        
        vector<int> vs1(26,0);
        vector<int> vs2(26,0);
        
        //count s1 frequency
        for(int i = 0 ; i <s1.size(); i++){
            vs1[s1[i]-'a']++;
        }
        
        //count s2 frequency and check vs1 == vs2
        for(int i = 0; i< s2.size(); i++) {
            
            vs2[s2[i]-'a']++;
            if(i > s1.size()-1) {
                vs2[s2[i-s1.size()]-'a']--;
            }
            
            if(vs1 == vs2) return true;
        }
        return false;
    }
};
