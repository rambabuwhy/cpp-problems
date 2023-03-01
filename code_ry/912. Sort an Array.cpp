/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
Problem: Sort an Array

------------------------------------------------------------------

Description:
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.


------------------------------------------------------------------

Solution:

In this implementation, we use insertion sort instead of quicksort for subarrays below a certain size threshold (16 in this case).
We also randomize the pivot selection by choosing a random index in the subarray instead of using a fixed index.

By incorporating these optimizations, we can improve the worst-case time complexity of the algorithm and further reduce the likelihood of encountering worst-case scenarios, which should help avoid the "Time Limit Exceeded" error for larger arrays.


------------------------------------------------------------------

Notes:

answer is still giving a "Time Limit Exceeded" error for large arrays, there are a few additional steps we can take to optimize the algorithm:

Use insertion sort for small subarrays: Quicksort is typically faster than other sorting algorithms for large arrays, but for very small subarrays, the overhead of the recursive calls can outweigh the benefits of the algorithm. 
One way to address this is to use a simpler sorting algorithm, such as insertion sort, for subarrays below a certain size threshold.

Randomize pivot selection: Although the median-of-three pivot selection method helps avoid worst-case behavior, it is still possible for the algorithm to encounter worst-case scenarios if the input array is already partially sorted or contains a large number of duplicate values. 
To mitigate this risk, we can randomize the pivot selection by choosing a random index in the subarray instead of using a fixed index.


------------------------------------------------------------------
*/

class Solution {
public:

    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));  // seed random number generator
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }

    void insertion_sort(vector<int>& nums, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            int j = i;
            while (j > left && nums[j] < nums[j - 1]) {
                swap(nums[j], nums[j - 1]);
                j--;
            }
        }
    }

    void qsort(vector<int>& nums, int left, int right) {
        if (left >= right) return;  // base case: subarray has size 0 or 1
        if (right - left + 1 <= 16) {  // use insertion sort for small subarrays
            insertion_sort(nums, left, right);
            return;
        }

        // choose random pivot
        int pivot_index = left + rand() % (right - left + 1);
        int pivot = nums[pivot_index];

        int i = left, j = right;
        while (i <= j) {
            while (nums[i] < pivot) i++;  // find element on left to swap
            while (nums[j] > pivot) j--;  // find element on right to swap
            if (i <= j) {
                swap(nums[i], nums[j]);  // swap elements and move indices
                i++;
                j--;
            }
        }

        qsort(nums, left, j);   // recursively sort left subarray
        qsort(nums, i, right);  // recursively sort right subarray
    }


};
