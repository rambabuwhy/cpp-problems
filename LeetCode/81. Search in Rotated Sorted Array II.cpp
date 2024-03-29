/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false


*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
       
        int left = 0, right =  nums.size()-1, mid;        
        while( left <= right ) {
            
            mid = left + ( right - left) / 2;             
            if(nums[mid] == target) return true;
            
            if((nums[left] == nums[mid]) && (nums[right] == nums[mid])) {
                left++; 
                right--;
            }else if(nums[left] <= nums[mid]) {
                if( (nums[left]<=target) && (nums[mid] > target) )  right = mid-1;
                else left = mid + 1; 
            }else {
                if((nums[mid] < target) &&  (nums[right] >= target) )  left = mid+1;
                else right = mid-1;
            }
        }
        return false;        
    }
};
