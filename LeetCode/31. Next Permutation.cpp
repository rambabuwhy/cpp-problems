/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i = nums.size() - 2;
        
        //step 1: find first decreasing element
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        //step 2: find j "just" larger than i and swap both
        int j = nums.size() - 1;
        if (i >= 0) {
            
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }            
            //swap i and j
            swap(nums, i, j);
        }
        //step 3: reverse from i+1 to last element
        reverse(nums.begin()+i+1, nums.end());
        
    }

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
