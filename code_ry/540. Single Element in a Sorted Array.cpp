/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
Problem: Single Element in a Sorted Array

------------------------------------------------------------------

Description:

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10


------------------------------------------------------------------

Solution:

The algorithm first initializes two pointers left and right to the beginning and end of the input array, respectively. 
It then enters a binary search loop that continues until the two pointers converge on the single element.

In each iteration of the loop, the algorithm computes the midpoint index mid between left and right. 
It then checks whether nums[mid] is equal to nums[mid ^ 1], where ^ denotes the bitwise XOR operation. 
If nums[mid] is equal to nums[mid ^ 1], then the single element must be to the right of mid, since all previous elements occur in pairs. 
Otherwise, the single element must be to the left of mid or at mid itself.

Based on this comparison, the algorithm updates either left or right to move closer to the single element. 
Specifically, if nums[mid] is equal to nums[mid ^ 1], then the single element must be to the right of mid, so the algorithm updates left = mid + 1 to exclude the midpoint from consideration in the next iteration. 
Otherwise, the single element must be to the left of mid or at mid itself, so the algorithm updates right = mid to include the midpoint in the next iteration.

The algorithm terminates when left and right converge on the single element. At this point, left points to the single element, which is returned as the result of the function.


------------------------------------------------------------------

Notes:

the solution provided is optimized in terms of time and space complexity. 
The time complexity of the algorithm is O(log n) because it uses binary search to find the single element in the sorted array. 
The space complexity is O(1) because the algorithm does not use any extra data structures.

The binary search algorithm has a logarithmic time complexity because it reduces the search space by half in each iteration. 
This means that the number of elements to search through decreases exponentially with each iteration, leading to a time complexity of O(log n).

Furthermore, the algorithm does not use any extra space, other than a few constant variables, which gives it a space complexity of O(1). 
This is an important optimization because it means that the algorithm can solve the problem efficiently without using a lot of memory.

Overall, the provided solution is an optimized approach to solving the problem of finding the single element in a sorted array.

------------------------------------------------------------------
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        
        // Binary search
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // Check if the single element is to the left or right of the midpoint
            if (nums[mid] == nums[mid ^ 1]) {
                // If nums[mid] == nums[mid ^ 1], then the single element is to the right of mid
                left = mid + 1;
            } else {
                // Otherwise, the single element is to the left of mid or mid itself
                right = mid;
            }
        }
        
        // At this point, left points to the single element
        return nums[left];
    }
};


