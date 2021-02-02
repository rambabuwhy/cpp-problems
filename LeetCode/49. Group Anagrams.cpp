/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> mmap = {};
        vector<vector<string>> result = {};
        
        if(strs.size() < 1) {
            return result;
        }
        
        for(auto str:strs){
            
            string original = str;
            sort(str.begin(),str.end());
            mmap[str].push_back(original);
                   
        }
        
        for(auto m:mmap){
            result.push_back(m.second);  
        }
        
        return result;
    }
  
};
