/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        int result=dp[0];

        for(int i=1; i<nums.size(); i++){
            dp[i]=(dp[i-1]>0?dp[i-1]:0) + nums[i];
            result=max(result,dp[i]);
        }
        return result;
    }
    /*
        int maxSubArray(vector<int>& nums) {
        
        int max_ending_here = 0;   // max at given index
        int max_so_far = INT_MIN;  //result: max of (max_ending_here)
        for(int i = 0; i < nums.size(); i++){
            max_ending_here += nums[i]; 
            if (max_so_far < max_ending_here)  max_so_far = max_ending_here;
            if (max_ending_here < 0) max_ending_here = 0;
        }
        return max_so_far;
    }
    */
};
