class Solution {
public:
    
    //already  sorted
    //cartesian product of the number of BST for its left and right subtrees,
    //if j is in between 1 to i  then  at node j, lefrt nodes:  j-1  and right is  i-j
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
