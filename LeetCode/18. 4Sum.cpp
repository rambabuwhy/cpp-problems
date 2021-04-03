/*
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [], target = 0
Output: []

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        if(nums.size() < 4) return vector<vector<int>>();
        
        vector<int> &arr = nums;
        sort(arr.begin(), arr.end());
        vector<vector<int>> quadruplets;
        for (int i = 0; i < arr.size() - 3; i++) {
          if (i > 0 && arr[i] == arr[i - 1]) {  // skip same element to avoid duplicate quadruplets
            continue;
          }
          for (int j = i + 1; j < arr.size() - 2; j++) {
            if (j > i + 1 &&
                arr[j] == arr[j - 1]) {  // skip same element to avoid duplicate quadruplets
              continue;
            }
            searchPairs(arr, target, i, j, quadruplets);
          }
        }
        return quadruplets;
        
    }
    void searchPairs(const vector<int> &arr, int targetSum, int first, int second,vector<vector<int>> &quadruplets) {
        int left = second + 1;
        int right = arr.size() - 1;
        while (left < right) {
          int sum = arr[first] + arr[second] + arr[left] + arr[right];
          if (sum == targetSum) {  // found the quadruplet
            quadruplets.push_back({arr[first], arr[second], arr[left], arr[right]});
            left++;
            right--;
            while (left < right && arr[left] == arr[left - 1]) {
              left++;  // skip same element to avoid duplicate quadruplets
            }
            while (left < right && arr[right] == arr[right + 1]) {
              right--;  // skip same element to avoid duplicate quadruplets
            }
          } else if (sum < targetSum) {
            left++;  // we need a pair with a bigger sum
          } else {
            right--;  // we need a pair with a smaller sum
          }
        }
    }
};
