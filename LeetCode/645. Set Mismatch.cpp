/*

You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]

*/


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
       
        int l_xor=0;
        int xor0=0, xor1=0;
        
        for (int n: nums)
        l_xor ^= n;
        
        for (int i = 1; i <= nums.size(); i++)
        l_xor ^= i;
        
        int rightmostbit = l_xor & ~(l_xor - 1);
        
        for (int n: nums) {
            if ((n & rightmostbit) != 0)
            xor1 ^= n;
            
            else
            xor0 ^= n;
        }
        
        for (int i = 1; i <= nums.size(); i++) {
            if ((i & rightmostbit) != 0)
            xor1 ^= i;
            else
            xor0 ^= i;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == xor0)
            return {xor0, xor1};
        }
        
        return {xor1, xor0};
          
    }
};
