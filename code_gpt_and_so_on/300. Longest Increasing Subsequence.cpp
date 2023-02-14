/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
Problem: Longest Increasing Subsequence

------------------------------------------------------------------
Description:
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

---------------------------------------------------------
Example:

Given the input array nums = [10, 9, 2, 5, 3, 7, 101, 18], the code initializes the dp array with the length of 1 for each index: dp = [1, 1, 1, 1, 1, 1, 1, 1].

In the first iteration of the outer loop, i = 0, and j ranges from 0 to 0. The inner loop does not execute, and dp[0] = 1.

In the second iteration of the outer loop, i = 1, and j ranges from 0 to 1. The inner loop executes once with j = 0, and the code compares nums[1] and nums[0]. Since nums[1] < nums[0], the inner loop ends and dp[1] = 1.

In the third iteration of the outer loop, i = 2, and j ranges from 0 to 2. The inner loop executes once with j = 0, and the code compares nums[2] and nums[0]. Since nums[2] < nums[0], the inner loop ends and dp[2] = 1.

In the fourth iteration of the outer loop, i = 3, and j ranges from 0 to 3. The inner loop executes twice, with j = 0 and j = 1. The code compares nums[3] and nums[0], and since nums[3] > nums[0], dp[3] = max(dp[3], dp[0] + 1) = 2. The inner loop then compares nums[3] and nums[1], and since nums[3] > nums[1], dp[3] = max(dp[3], dp[1] + 1) = 2.

This process continues for the remaining indices in the input array, and the final value of dp is [1, 1, 1, 2, 2, 3, 4, 4]. The code then finds the maximum value of dp, which is 4, and returns it as the answer.

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
