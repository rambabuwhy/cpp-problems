/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        //set stores in increasing order by default
        multiset<int> lset;
        vector<int> sqr(nums.size());        
        for(int i=0; i<nums.size(); i++){
            lset.insert(nums[i] * nums[i]);
        }
        
        //result should be in vector
        copy(lset.begin(), lset.end(), sqr.begin());        
        return sqr;
    }
};
