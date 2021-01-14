
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
        if(s.length()<=1){
            return s;
        }
        
        vector<vector<bool>> dp(s.length(),vector<bool>(s.length()));
        string result;
        int maxLength=0;
        
        //store single char in result
        //no need to store all  single char: first single char as result of length 1
        for(int i=0; i<s.length(); i++){
            
            dp[i][i]=true;
            
            if(maxLength < 1){
                result=s[i];
                maxLength=1;
                               
            }
            
        }

        for(int startIndex = s.length()-1; startIndex>=0; startIndex--){
            for(int endIndex = startIndex+1;  endIndex<s.length();  endIndex++){
                //palindrome : compare last two char
                if(s[startIndex]==s[endIndex]){ 
                    //then remaining string should be palindrome
                    if( dp[startIndex+1][endIndex-1] || (endIndex-startIndex)==1) {  
                        dp[startIndex][endIndex]=true;
                        if(maxLength < endIndex-startIndex+1){
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
