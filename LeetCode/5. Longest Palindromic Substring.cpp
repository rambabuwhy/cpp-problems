
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
        int maxLen=0;
        for(int i=0;i<s.length();i++){
            dp[i][i]=true;
            if(maxLen < 1){
                result=s[i];
                maxLen=1;
            }
        }

        for(int i=s.length()-1;i>=0;i--){
            for(int j=i+1;j<s.length();j++){
                if(s[i]==s[j]){
                    if(dp[i+1][j-1] || (j-i)==1){
                        dp[i][j]=true;
                        if(maxLen<j-i+1){
                            cout<<"j-i:"<<j-i+1<<endl;
                            result=s.substr(i,j-i+1);
                            maxLen=max(maxLen,j-i+1);

                        }
                    }
                }
            }
        }
        return result;
    }
};
