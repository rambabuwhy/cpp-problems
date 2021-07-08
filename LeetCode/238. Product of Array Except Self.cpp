/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> result(nums.size());
        if (nums.size() < 2 )   return result;
               
        result[0] = 1;
        for (int i = 1 ; i < nums.size(); i++) {
            result[i] = nums[i-1] * result[i-1];
        }
        
        int right = 1;
        for (int j = nums.size()-1; j >= 0; j--) {
            result[j] = result[j] * right;
            right = right * nums[j];
        }
        return result;
    }
};
