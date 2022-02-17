/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        backTrack(target, candidates, 0, result, curr);
        return result;
        
    }
    
    void backTrack(int target, vector<int>& candidates,int index, vector<vector<int>> &result,vector<int> &curr){
        
        if(target == 0 ){
            result.push_back(curr);
            return; 
        } else if ( target < 0){
            return;
        }
        
        for(int i=index; i<candidates.size(); i++){
            curr.push_back(candidates[i]);
            backTrack(target-candidates[i], candidates,  i, result, curr);
            curr.pop_back();
        } 
        
    }
};
