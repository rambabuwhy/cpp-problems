/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
*/

class Solution {
public:
    //case: sure we can reach end, but find minimum steps
    //Update farthest to i + nums[i] if the latter is larger.
    //If we reach currentJumpEnd, it means we finished the current jump, and can begin checking the next jump by setting currentJumpEnd = farthest
    int jump(vector<int>& nums) {
        
        int minJumps = 0;
        int maxJump = 0;
        
        int currJump = 0;
        for(int i=0; i<nums.size()-1; i++){  
            maxJump = max(maxJump, i+nums[i]);
            if(i == currJump){
                minJumps++;
                currJump = maxJump;
            }
        }
        return minJumps; 
    }
};
};
