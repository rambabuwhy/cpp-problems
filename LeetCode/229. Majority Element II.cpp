/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]

*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int count1=0;
        int count2=0;
        
        int cand1=INT_MIN;
        int cand2=INT_MIN;
        
        //find candidate
        for(int n:nums){
            
            if(cand1 != INT_MIN && n == cand1) count1++;
            
            else if(cand2 != INT_MIN &&  n == cand2)  count2++;
            
            else if(count1 == 0) cand1 = n, count1++;
            
            else if(count2 == 0) cand2 = n,count2++;
              
            else count1--,count2--;
        }
        
        //verify candidate
        
        count1=0;
        count2=0;
        for(int n:nums){
            
            if(cand1 != INT_MIN && cand1 == n) count1++;
            if(cand2 != INT_MIN && cand2 == n) count2++;
        }
        
        vector<int> result;
        if(count1 > nums.size()/3) result.push_back(cand1);
        
        if(count2 > nums.size()/3) result.push_back(cand2);
        
        return result;
        
        
        
    }
};
