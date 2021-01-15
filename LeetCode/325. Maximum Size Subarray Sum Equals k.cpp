/*
Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:

Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4 
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2, -1, 2, 1], k = 1
Output: 2 
Explanation: The subarray [-1, 2] sums to 1 and is the longest.

*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        
        unordered_map<int,int> umap; // <sum, index>
        
        int csum = 0; //cumilative sum
        int maxSize = 0;
        
        for(int i =0; i<nums.size(); i++) {
            
            csum = csum + nums[i];
            
            //from i=0 found sum
            if(csum == k)
            maxSize = i +1;
        
             //store all sum and index i
            if(umap.find(csum) == umap.end())
            umap[csum] = i;
         
            //i - umap[csum-k]
            if(umap.find(csum-k) != umap.end())
            maxSize= max(maxSize, i- umap[csum -k]);
                   
        }
        
        return maxSize;
        
    }
};
