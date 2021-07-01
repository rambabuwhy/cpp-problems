
/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

*/

class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.length() <= 1){
            return s;
        }
        
        vector<vector<bool>> dp(s.length(),vector<bool>(s.length()));
        string result;
        int maxLength = 0;
        
        // every string with one character is a palindrome
        for(int i=0; i<s.length(); i++){
            
            dp[i][i] = true;
            
            //save that string  and  length
            if(maxLength < 1){
                result = s[i];
                maxLength = 1;                   
            } 
        }

        //logic
        for(int startIndex = s.length()-1; startIndex >= 0; startIndex--){
            for(int endIndex = startIndex+1;  endIndex < s.length();  endIndex++){
                
                if(s[startIndex]==s[endIndex]) { //palindrome : compare last two char
                    //then remaining string should be palindrome
                    if( dp[startIndex+1][endIndex-1] || (endIndex-startIndex)==1) {  
                        
                        dp[startIndex][endIndex] = true;
                        if(maxLength < endIndex-startIndex+1) {
                            
                            //save string and length
                            result=s.substr(startIndex, endIndex-startIndex+1);
                            maxLength=max(maxLength, endIndex-startIndex+1);
                        }
                    } 
                }
            }
        }
        return result;
    }
};
