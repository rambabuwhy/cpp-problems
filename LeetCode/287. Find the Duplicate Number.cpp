/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        if(nums.size() <= 1){
            return 0;
        }
        int T = nums[0];
        int H = nums[0];
        do{
            T = nums[T];
            H = nums[nums[H]];
            
        }while(T != H);
        
        T = nums[0];
        while ( T != H){
            T = nums[T];
            H = nums[H];
        }
        
        return T;
        
    }
};
