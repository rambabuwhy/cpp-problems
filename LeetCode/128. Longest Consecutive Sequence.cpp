/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

*/



class Solution {
public:
    
    //store all numser into set
    //iterate nums and search num+1 in set
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> uset(nums.begin(), nums.end());
        
        int result = 0;
       
        for(auto num:nums){
            if(uset.find(num-1) == uset.end()){
                int curr_num = num;
                int curr_result = 1;
                while(uset.find(curr_num+1) != uset.end()){
                    curr_num++;
                    curr_result++;
                }
                result = max(result,curr_result);
            }
        }
        
        return result;
    }
};
