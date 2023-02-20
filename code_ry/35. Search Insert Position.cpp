/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
Problem: Search Insert Position

------------------------------------------------------------------

Description:
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4


------------------------------------------------------------------

Solution:

We start with two pointers: left pointing to the beginning of the array and right pointing to the end of the array.
We enter a loop that continues while left is less than or equal to right.
We compute the index of the middle element using the formula mid = left + (right - left) / 2. This formula avoids integer overflow by using subtraction instead of addition.
We compare the middle element nums[mid] with the target value:
If nums[mid] equals the target value, we have found the target index and return mid.
If nums[mid] is less than the target value, we search the right half of the array by updating left to mid + 1.
If nums[mid] is greater than the target value, we search the left half of the array by updating right to mid - 1.
If we exit the loop without finding the target index, we return the insertion index, which is equal to the value of left. 
This is because left points to the first element in the array that is greater than or equal to the target value, which means that inserting the target value at left would maintain the sorted order of the array.


------------------------------------------------------------------

Notes:

The time complexity of this algorithm is O(log n), where n is the length of the input array. 
This is because the binary search algorithm divides the input array in half at each iteration, so the maximum number of iterations required to find the target index or the insertion index is log2(n).

The space complexity of this algorithm is O(1), because we only use a constant amount of extra space to store the pointers and variables needed for the binary search.


------------------------------------------------------------------
*/
int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

