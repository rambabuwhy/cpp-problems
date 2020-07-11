class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> M;
        for(auto i:nums){
            M[i]++;            
        }
        for(auto i:M){
            if(i.second > nums.size()/2){
                return i.first;
            }
        }
        return -1;;
        
    }
};
