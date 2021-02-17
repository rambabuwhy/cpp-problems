/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        if(nums.size()<2) return {};
        
        unordered_map<int,int> map;
        
        for(int i=0;i<nums.size();i++){
            auto itr = map.find(target-nums[i]);
            if(itr != map.end()){
                return {i,itr->second};                
            }
            else{
                map[nums[i]]=i;
            }
        }
        return {};
    }
};
