/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        if(nums.size() < 1) return 0;
       
        int result = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            result = result ^ nums[i];
        }
        
        return result;
        
    }
};
