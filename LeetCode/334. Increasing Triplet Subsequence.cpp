/*

Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

*/


/*
    first_num = second_num = some very big number
    for n in nums:
        if n is smallest number:
            first_num = n
        else if n is second smallest number:
            second_num = n
        else n is bigger than both first_num and second_num:
        # We have found our triplet, return True


*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int F = INT_MAX;
        int S = INT_MAX;
        
        for (int i = 0 ; i<nums.size(); i++){
            
            if(F >= nums[i])
            F = nums[i];
                
            else if( S >= nums[i])
            S = nums[i];
            
            else
            return true;
            
        }
        
        
        return false;
        
    }
};
