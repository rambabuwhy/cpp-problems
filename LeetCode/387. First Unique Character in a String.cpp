/*
Given a string s, return the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1

*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,int> lmap;        
        //step 1: find frequency of each element
        for(auto c: s){
            lmap[c]++;
        }
        
        //step 2: iterate again and find first one with frequency is 1
        for(int i =0; i<s.length(); i++){
            if(lmap[s[i]] == 1)  return i;
        }
        return -1;
    }
};
