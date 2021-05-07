/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/


class Solution {
public:
    //use map: element -> frequesnce
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(auto i:nums){
            umap[i]++;            
        }
        for(auto itr:umap){
            if(itr.second > nums.size()/2){
                return itr.first;
            }
        }
        return -1;
    }
};


class Solution {
public:
    //Boyer-Moore Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = -1;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            //if same number  then +1 else -1
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};
