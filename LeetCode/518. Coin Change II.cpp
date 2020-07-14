/*

You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(coins.size() < 1 && amount < 1)  return 1;
        if(coins.size() < 1 && amount > 0) return 0;
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1));
        
        for(int i = 0 ; i < coins.size();i++) {
            dp[i][0] = 1;
        }
        
        for(int i = 0; i < coins.size(); i++){
            for(int j = 1; j <= amount; j ++){
                if( i > 0){
                    dp[i][j]=dp[i-1][j];
                }
                if(j >= coins[i]){
                    dp[i][j] = dp[i][j] + dp[i][j - coins[i]];
                }
            }
        }
        
        return dp[coins.size()-1][amount];
        
        
    }
};
