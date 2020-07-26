/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int L = 0, H = nums.size() - 1;

        while (L < H) {
            int M = L + (H - L) / 2;
            //case 1: if Middle and high  same  
            //we dont know where min element. we just move H to left by 1
            if (nums[M] == nums[H])
                H = H - 1;
            
            //case 2: if H is minimum  than M  the search in right  half
            else if (nums[M] > nums[H])
                L = M + 1;
            
            //case 3: if H is maximum than M  then search in left half
            else
                H = M;
        }
        return nums[L];
    }
};
