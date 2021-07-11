/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [1,1]
Output: 1
Example 4:

Input: nums = [1,1,2]
Output: 1
*/

class Solution {
public:
    
    //Floyd's Tortoise and Hare (Cycle Detection)
    //if cycle exist; find begining of the cycle
    int findDuplicate(vector<int>& nums) {
        
        if(nums.size() <= 1) return 0;
    
        //find cycle
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
            
        } while(slow != fast);
        
        //find begining of the cycle
        slow = nums[0];
        while ( slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
