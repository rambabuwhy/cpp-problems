/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

*/


class Solution {
public:
    int countSubstrings(string s) {
        
        int result = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),false));
        
        //all single chanracter is palindrome
        for(int i=0; i<s.size(); i++){
            dp[i][i] = true;
            result++;
        }
        
        //remaining
        for(int i=s.size()-1; i>=0; i--){
            for(int j=i+1; j<s.size(); j++){
                 
                if(s[i] == s[j]){
                    //i+1 = j  => two character string and both are equal is palindrome
                    if(dp[i+1][j-1] == true || j-i ==1){
                        dp[i][j] = true;
                        result++;
                    }
                }
                
            }
        }
        return result; 
    }
};
