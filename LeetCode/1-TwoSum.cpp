class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size()<2) return {};
       unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            auto itr = map.find(target-nums[i]);
            if(itr != map.end()){
                return {i,itr->second};
            }
            else{
                map[nums[i]]=i;
            }
        }
        return {};
    }
};
