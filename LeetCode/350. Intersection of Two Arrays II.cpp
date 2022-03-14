/*
Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

*/

class Solution {
public:    
    
    //construct frequency map of nums2(large size)
    //iterate small one and find result array
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> result;
        unordered_map <int, int> umap;        
        
        if(nums1.size() == 0 || nums2.size() ==0) return vector<int>();
                
        //make nums2 is big always
        if(nums2.size() < nums1.size()) intersect(nums2, nums1);        

        //frequency count for nums2
        for(auto num:nums2) umap[num]++;
        
        //iterate nums1 and find in nums2 map
        for(auto num:nums1){            
            if(umap[num]-- > 0) result.push_back(num);
        }
        return result;
    }
};
