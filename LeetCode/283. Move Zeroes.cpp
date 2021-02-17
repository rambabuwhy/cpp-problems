/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int non_zero = 0;
        
        //move all non-zero to front
        for(int i = 0 ; i < nums.size();i++){
            if(nums[i] != 0 ){
                nums[non_zero++]=nums[i];
            }
        }
        
        //insert 0 in remaining slots till end
        while(non_zero < nums.size()){
            nums[non_zero++] = 0;
        }
        
    }
};
