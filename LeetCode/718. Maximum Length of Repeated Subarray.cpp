/*

Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5

*/


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1));
        int result = 0;
  
        for(int i=1; i<=nums1.size(); i++) {
            for(int j=1; j<=nums2.size(); j++) {
                
                //if both are same; substring of previous + 1
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    result = max(result, dp[i][j]);
                } 
                
                //if not same: new substring start: so assign current one to 0
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return result;
    }
};
