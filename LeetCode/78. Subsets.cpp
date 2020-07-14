/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> curr;
        subsetsUtil(nums,result,curr,0);
        
        return result;
        
    }
    void subsetsUtil(vector<int> & nums,vector<vector<int>>&result, vector<int>&curr, int start){
        result.push_back(curr);
        for(int i = start; i<nums.size(); i++){
            curr.push_back(nums[i]);
            subsetsUtil(nums,result,curr,i+1);
            curr.pop_back();
        }
    }
};
