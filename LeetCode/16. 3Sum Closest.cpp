/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ctarget=INT_MAX;
        for(int itr = 0; itr < nums.size()-2; itr++){
            int left = itr+1;
            int right = nums.size()-1;
            while(left < right){
                int diff = target - nums[itr] - nums[left] - nums[right];
                if(diff == 0) return target - diff;
                if(abs(diff)<abs(ctarget)) ctarget = diff;
                if(diff > 0) left++;
                else right--;
            }

        }
        return target - ctarget;

    }
};
