/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.
*/
class Solution {
public:
    void swap(vector<int> &nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        
    }
    void sortColors(vector<int>& nums) {
        if(nums.size() < 1 )  return;
        int L = 0;
        int M = 0;
        int R = nums.size() -1;
        while( M<=R ) {
            cout<<"M:"<<nums[M]<<" ";
            switch(nums[M]) {
                case 0:
                    swap(nums,L, M);
                    L++;
                    M++;
                    break;
                case 1:
                    M++;
                    break;
                case 2:
                    swap(nums,M,R);
                    R--;
                    break;
            }
        }
        
    }
};
