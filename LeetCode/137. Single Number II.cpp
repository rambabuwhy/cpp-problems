/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenOnce = 0, seenTwice = 0;
        for(int num:nums){
             seenOnce = ~seenTwice & (seenOnce ^ num);
            seenTwice = ~seenOnce & (seenTwice ^ num);
            
        }
        return seenOnce;
       
        
    }
};
