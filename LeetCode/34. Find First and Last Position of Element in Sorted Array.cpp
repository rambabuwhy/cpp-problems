/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], tar

*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int start = 0, end = nums.size(), mid, left, right;
        
        //left position
        //compare target with ">=" gives lower bound
        while (start < end) {
            mid = (start + end) / 2;
            if (nums[mid] >= target)
                end = mid;
            else
                start = mid + 1;
        }
        left = start;
        
        //right position
        //compare target with ">"  gives right bound
        start = 0, end = nums.size();
        while (start < end) {
            mid = (start + end) / 2;
            if (nums[mid] > target)
                end = mid;
            else
                start = mid + 1;
        }
        right = start;
        
        return left == right ? vector<int> {-1,-1} : vector<int> {left,right-1};
    }
};
