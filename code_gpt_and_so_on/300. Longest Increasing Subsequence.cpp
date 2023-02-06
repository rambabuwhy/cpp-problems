/*
Problem:
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
--------------------------------------------------------
Solution:
The dp array is initialized to have a length of 1 for each index. This represents that each element is itself a LIS.
In the outer loop, we iterate through each index i of the input array nums.
In the inner loop, we iterate from the start to the current index i.
For each index j in the inner loop, if the current number at index i is greater than the number at index j, we update the dp value at index i to be the maximum of its current value and dp[j] + 1.
Finally, we find the maximum length of LIS by iterating through the dp array and finding the maximum value.

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); // dp[i] stores the length of LIS ending at index i
        
        // iterate through the entire array
        for (int i = 0; i < n; i++) {
            // iterate from the start to the current index i
            for (int j = 0; j < i; j++) {
                // if the current number is greater than the number at j, update dp[i]
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        // find the maximum length of LIS
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[i]);
        }
        
        return ans;
        
    }
};
