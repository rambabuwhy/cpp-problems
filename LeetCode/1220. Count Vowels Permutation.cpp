/*
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

*/

class Solution {
public:
    int countVowelPermutation(int n) {
        
        int MOD = 1e9 + 7;
        
        // dp[n][i] is the number of strings of length n starting at char i
        vector<vector<long>> dp(n+1, vector<long>(5)); 
        
        // 1 string of length n that start with char i
        for (int i = 0; i < 5; i++){
            dp[1][i] = 1;
        }
             
        vector<vector<long>> relation = {{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}};
        for (int i = 1; i < n; i++) { 
            for (int j = 0; j < 5; j++) { 
                dp[i + 1][j] = 0;
                for (int k : relation[j]) {
                    dp[i + 1][j] = dp[i + 1][j] + dp[i][k] % MOD;
                }
            }
        }

        long result = 0;
        for (int i = 0; i < 5; i++){
            result = (result + dp[n][i]) % MOD;
        }
            
        return (int)result;
        
    }
};
