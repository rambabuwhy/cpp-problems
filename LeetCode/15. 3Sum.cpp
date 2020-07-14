/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size() < 3) return {};
        
        //result  vector
        vector<vector<int>> result;
        
        //sort
        sort(nums.begin(),nums.end());
        
        for(int itr=0; itr < nums.size()-2; itr++){
            //skip duplicate 
            if(itr > 0 && nums[itr] == nums[itr - 1]) {continue;}
            
            //two pointers to iterate from  start and end
            //start always pointing next to itr
            int start = itr+1;
            int end =nums.size()-1;
            
            //iterate
            while(start<end){
                int target = nums[start] + nums[end];
                
                //if found move both start and end.
                if( target == -nums[itr]){
                    
                    //store
                    result.push_back({nums[itr],nums[start],nums[end]});
                    
                    //move start and  end pointers
                    start++;
                    end--;
                    
                    //move pointers forward if  duplicates
                    while (start < end && nums[start] == nums[start - 1]) start++;
                    while (start < end && nums[end] == nums[end + 1]) end--;
                }
                
                //if not found  move either start  or end
                else if(target < -nums[itr]) start++;
                else end--;
            }
        }
        return result;
        
        
    }
};