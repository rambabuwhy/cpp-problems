/*
Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

 

Example 1:

Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Example 2:

Input: nums = [4,2,3,4]
Output: 4

*/

class Solution {
public:
    
    //Sorting
    int triangleNumber(vector<int>& nums) {
        
        int n = nums.size();
        int result = 0;
        
        sort(nums.begin(), nums.end());
        for (int i = n-1; i >= 0; i--) {
            
            int lo = 0;
            int hi = i-1;
            while (lo < hi) {
                if (nums[lo] + nums[hi] > nums[i]) {
                    
                    //all elements between lo-hi satisfies
                    result += hi - lo;
                    hi--;
                }
                else {
                    lo++;
                }
            }
        }
        return  result;
    }
};
