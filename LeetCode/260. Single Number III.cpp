/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int> result;
        int bitmask = 0;
        
        //XOR of All numbers
        for (int num : nums) {
            bitmask ^= num;
        }
        
        //Logic:  get x and y from bitmask
        //find rightmost  bit 1  which is different of x from y
        
        // rightmost 1-bit diff between x and y
        int diff = bitmask & (-bitmask);

        int x = 0;
        // bitmask which will contain only x
        for (int num : nums) {
            if ((num & diff) != 0) {
                x ^= num;
            }
        }
        
        int y = bitmask ^ x;
        
        result.push_back(x);
        result.push_back(y);
        return result;
        
    }
};
