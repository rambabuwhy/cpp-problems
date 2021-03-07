/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]

*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> curr;
        util(nums, result, 0);
        return result;
        
    }
    
    
    void util(vector<int> &nums, vector<vector<int>> &result, int first) {
        
        if(first == nums.size()){
            result.push_back(nums);
            return;
        }
        
        for(int i = first; i<nums.size(); i++){
            swap(nums[i], nums[first]);
            util(nums, result, first+1);
            swap(nums[i], nums[first]);
        }
    }
};
