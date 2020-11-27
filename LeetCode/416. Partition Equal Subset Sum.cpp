/*

Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

*/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        if(nums.size() < 2) return false;
        
        int sum = 0;
        
        for(auto n:nums)
        sum = sum + n;
        
        
        if(sum % 2 != 0) 
        return false;
        
            
        sum = sum / 2;
        
        
        vector<vector<bool>>  dp(nums.size(), vector<bool>(sum + 1));
        
        
        for(int i = 0; i<nums.size();i++)
        dp[i][0]=true;
        
        for(int j = 1; j<=sum; j++)
        dp[0][j] = (sum==nums[0])?true:false;
        
        
        for(int i = 1; i < nums.size(); i++ ) {
            
            for(int j = 1; j <= sum;  j++ ) {
                
                if(dp[i - 1][j])
                dp[i][j] = dp[i-1][j];
                
                else if( j >= nums[i])
                dp[i][j] = dp[i-1][j-nums[i]];
                
                
            }
        }
        
        return dp[nums.size()-1][sum];
        
    }
};
