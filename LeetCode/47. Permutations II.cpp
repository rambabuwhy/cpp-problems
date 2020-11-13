/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

*/

class Solution {
public:
    
    void dfs(vector<vector<int>>& result, int pos, vector<int>& nums)
    {
        if(pos == nums.size())
        {
            result.push_back(nums);
            return;
        }
        
        //use set to check already processed or not.  
        //if the number already processed , just do nothing ie: no dfs call 
        unordered_set<int> Set;
        for(int i = pos; i < nums.size(); ++i)
        {
            if (Set.count(nums[i]) == 1) { continue; }
            Set.insert(nums[i]);
            swap(nums[i], nums[pos]);
            dfs(result, pos + 1, nums);
            swap(nums[i], nums[pos]);
        }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()) return result;
        sort(nums.begin(), nums.end());
        dfs(result, 0, nums);
        return result;
        
    }
};
