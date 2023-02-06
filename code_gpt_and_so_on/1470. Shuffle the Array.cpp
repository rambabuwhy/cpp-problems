/*
problem:
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].

 

Example 1:

Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7] 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
Example 2:

Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]
Example 3:

Input: nums = [1,1,2,2], n = 2
Output: [1,2,1,2]
---------------------------------------------------------------------------
Solution:
The code uses a single loop that iterates n times, where n is the number of pairs of x_i and y_i elements in the input array.

In terms of space complexity, the code creates a new result vector, which has the same size as the input array. So, the space complexity is also O(n).

Pre-allocating memory for the result vector using reserve can improve the performance if the size of the input array is known beforehand, as it avoids reallocation during the push_back operations.


*/


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        std::vector<int> result;
        result.reserve(nums.size()); // Pre-allocate memory to avoid reallocation
        for (int i = 0; i < n; i++) {
            result.push_back(nums[i]); // Add xi to the result array
            result.push_back(nums[i + n]); // Add yi to the result array
        }
        return result;        
    }
};
