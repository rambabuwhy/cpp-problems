/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
Problem: Kth Missing Positive Number

------------------------------------------------------------------

Description:
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

 

Example 1:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
 


------------------------------------------------------------------

Solution:

o solve this problem, we can use binary search. We can find the number of missing integers between arr[0] and arr[mid] by subtracting the index of mid from arr[mid]. 
If this count is less than k, then we know that the kth missing integer must be greater than arr[mid]. Otherwise, the kth missing integer must be less than or equal to arr[mid]. 
We can continue this process until we find the kth missing integer.
Note that we add k to the index of the smallest element with k or more missing integers to get the kth missing integer.


------------------------------------------------------------------

Notes:

In the solution provided earlier, the variable left represents the number of missing integers in the array up to the mid index. So if left is less than k, then it means that the kth missing positive integer lies in the right half of the array, and we need to update the search range to the right of mid.

Therefore, the return statement return mid + k - left calculates the kth missing positive integer that lies in the right half of the array. The mid value gives the position of the last positive integer present in the left half of the array. The variable k represents the kth missing positive integer we are looking for. 
And left represents the number of missing integers up to the mid index. So by subtracting left from k, we get the number of missing integers we still need to find. Finally, we add this number to mid to get the position of the kth missing positive integer in the array.

If the kth missing positive integer is not present in the right half of the array, then we would have updated the search range to the left half of the array, and we would calculate the kth missing positive integer as left + k. Here, left gives the number of missing integers in the left half of the array, and k gives the position of the kth missing positive integer among these missing integers. Adding left to k gives the position of the kth missing positive integer in the array.

------------------------------------------------------------------
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int left = 0, right = n-1, mid;
        while (left <= right) {
            mid = left + (right-left)/2;
            // Number of missing integers between arr[0] and arr[mid]
            int count = arr[mid] - mid - 1;
            // If count is less than k, search in the right half
            if (count < k) {
                left = mid + 1;
            }
            // If count is greater than or equal to k, search in the left half
            else {
                right = mid - 1;
            }
        }
        // At this point, left is the index of the smallest element
        // that has k or more missing integers before it
        return left + k;
    }
};


