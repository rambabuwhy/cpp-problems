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
        
        //step 1: find first decreasing element: i
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        
        //step 2: find "just" larger than i  called j
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            
            //step 3: swap i and j
            swap(nums, i, j);
        }
        
        //step 4: reverse
        reverse(nums.begin()+i+1, nums.end());
        
    }
    
  

    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
