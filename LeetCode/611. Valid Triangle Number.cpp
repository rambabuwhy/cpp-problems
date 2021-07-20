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
  
        sort(nums.begin(), nums.end());
        int result = 0;
        
        //for every element  search other two using binary search
        for (int i = nums.size()-1; i >= 0; i--) {
            
            int left = 0;
            int right = i-1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    
                    //all elements between left-right satisfies
                    result += right - left;
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return  result;
    }
};


