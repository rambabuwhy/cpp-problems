/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        stack<int> l_stack;
        
        int l=nums.size();
        int r=0;
        
        //find minimum element from left
        for(int i =0; i<nums.size(); i++){
            
            while(!l_stack.empty() && (nums[l_stack.top()] > nums[i])) {
                    l = min(l, l_stack.top());
                    l_stack.pop();
            }
            l_stack.push(i);
        }
        
        l_stack = stack<int>();
        
        //find maxumum element from right
        for (int i = nums.size() - 1; i >= 0; i--) {
            
            while (!l_stack.empty() && (nums[l_stack.top()] < nums[i])){
                    r = max(r, l_stack.top());
                    l_stack.pop();
            }
                
            l_stack.push(i);
        }
        
        return r - l > 0 ? r - l + 1 : 0;
        
    }
};
