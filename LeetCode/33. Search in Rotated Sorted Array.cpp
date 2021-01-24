/*
You are given an integer array nums sorted in ascending order (with distinct values), and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() < 1) return -1;
        
        int l = 0;
        int h = nums.size()-1;
        
        while(l <= h){
            
            int m = l + (h - l) / 2;
            if(nums[m] == target) {
                return m;
            } else if (nums[l] <= nums[m]) {
                if(target >= nums[l] && target < nums[m]) {
                    h = m -1;
                    
                } else {
                    l = m +1;
                }
            } else {
                if(target <= nums[h] && target > nums[m]){
                    l = m + 1;
                } else {
                    h = m - 1;
                }
                
            }
            
        }
        return -1;
        
    }
};
