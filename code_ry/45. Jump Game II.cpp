/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
Problem:  Jump Game II

------------------------------------------------------------------

Description:
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
-------------------------------------------------
Solution:
The solution uses the greedy algorithm approach. The algorithm keeps track of two pointers, end and farthest, and a count of jumps jumps.

The for loop starts from the first index 0 and continues until the second-last index n - 1. In each iteration, the algorithm updates the maximum reachable index from the current index by farthest = max(farthest, i + nums[i]). If the current index i is equal to the end index end, it means that it is not possible to move further from the current index, so the end index is updated to the farthest reachable index end = farthest and the number of jumps is incremented by 1.

Finally, the code returns the number of jumps after the loop has finished.
--------------------------------------------------------------
The time complexity of this solution is O(n), where n is the length of the nums array. This is because in the for loop, each element is processed only once and the operations performed in each iteration take constant time.

The space complexity of this solution is O(1), because the algorithm only uses a few variables to store the indices and the number of jumps, which takes constant space, regardless of the size of the input array.
*/


#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    int jumps = 0, end = 0, farthest = 0;
    for (int i = 0; i < n - 1; i++) {
        farthest = max(farthest, i + nums[i]); // update the maximum reach
        if (i == end) { // if the current index is equal to the end, update end and increment jumps
            end = farthest;
            jumps++;
        }
    }
    return jumps;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Minimum jumps: " << jump(nums) << endl;
    return 0;
}
