/*

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]


*/

class Solution {
public:
    
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] !=  s[end--])
            return false;
        }
        
        return true;
    }
    
    void dfs(string s, int start,vector<string> &curr, vector<vector<string>> &result){
        
        if(start >= s.size()) result.push_back(curr);
       
        for(int end = start; end<s.size(); end++){
            
            if(isPalindrome(s,start,end)) {
                curr.push_back(s.substr(start,end-start+1));
            
                dfs(s,end+1,curr,result);
                curr.pop_back();
                
            }
           
        }
        
    }
    vector<vector<string>> partition(string s) {
        
        vector<string> curr;
        vector<vector<string>>result;
        dfs(s,0,curr,result);
        return  result;
        
        
        
        
    }
};
