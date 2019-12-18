class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ctarget=INT_MAX;
        for(int itr = 0; itr < nums.size()-2; itr++){
            int left = itr+1;
            int right = nums.size()-1;
            while(left < right){
                int diff = target - nums[itr] - nums[left] - nums[right];
                if(diff == 0) return target - diff;
                if(abs(diff)<abs(ctarget)) ctarget = diff;
                if(diff > 0) left++;
                else right--;
            }

        }
        return target - ctarget;

    }
};
