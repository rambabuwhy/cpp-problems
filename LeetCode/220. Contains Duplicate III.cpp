/*

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false

*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        set<long> Set;
        
        for(int i = 0; i<nums.size(); i++){
            
            //window exceede remove start element       
            if(i > k) Set.erase((long)nums[i-k-1]);
            
            //find second element which nums[i]-t  lowerbound helps
            auto itr = Set.lower_bound((long)nums[i]-t);
            
            
            //return if we find 
            if(itr != Set.end() && *itr-nums[i]<=t) return true;
            
            Set.insert(nums[i]);
            
        }
        
        return false;
        
    }
};
