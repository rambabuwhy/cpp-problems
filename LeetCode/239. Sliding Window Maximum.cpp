/*

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
Example 3:

Input: nums = [1,-1], k = 1
Output: [1,-1]
Example 4:

Input: nums = [9,11], k = 2
Output: [11]
Example 5:

Input: nums = [4,-2], k = 2
Output: [4]
 
 
 
*/
 
 class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> result;
        
        for (int i=0; i<nums.size(); i++) {
            
            // remove indexes of elements not from sliding window
            if (!dq.empty() && dq.front() == i-k) 
            dq.pop_front();
            
            // remove from deq indexes of all elements 
            // which are smaller than current element nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
            
            dq.push_back(i);
            
            if (i>=k-1) 
            result.push_back(nums[dq.front()]);
        }
        
        return result;
        
        
    }
};
