/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> curr;
        subsetsUtil(nums, result, curr, 0);
        
        return result;  
    }
    
    void subsetsUtil(vector<int> & nums, vector<vector<int>>&result, vector<int>&curr, int start){
        
        result.push_back(curr);
        
        //why i+1?  i has limit i<nums.size in for loop
        //if start+1;  no limit; recusrsion goin in calling for all infinite values
        for(int i = start; i<nums.size(); i++){
            curr.push_back(nums[i]);
            subsetsUtil(nums, result, curr, i+1);
            curr.pop_back();
        }
    }
};
