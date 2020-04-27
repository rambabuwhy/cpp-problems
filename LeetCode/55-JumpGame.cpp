class Solution {
public:
    bool canJump(vector<int>& nums) {
        int L = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= L) {
                L = i;
            }
        }
        return L == 0;
    }
};
