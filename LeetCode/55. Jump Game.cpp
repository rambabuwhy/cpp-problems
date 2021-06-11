/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

*/




class Solution {
public:
    // if i+nums[i] can reach lastPos then move lastPos from N to i and
    //finally check lastpos is at 0th position or not
    bool canJump(vector<int>& nums) {  
        int lastPos = nums.size()-1;
        for(int i=nums.size()-1; i>=0; i--){
            if(i+nums[i] >= lastPos){
                lastPos = i;
            }
        }  
        return lastPos == 0;
    }
};
