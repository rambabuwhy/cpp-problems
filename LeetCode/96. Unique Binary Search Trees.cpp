/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
*/
class Solution {
public:
    
    //already  sorted
    //bst at node i  is  
    //left: (1 to i-1)  root: i  right (i+1 to n)
    int numTrees(int n) {
        
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];        
    }
};
