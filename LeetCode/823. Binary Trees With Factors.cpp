/*
Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
Example 2:

Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].

*/

class Solution {
public:
    //non leaf node : if A[j] is one child  then A[i]/A[j] is second one
    //number of ways at A[i]  = A[j] * (A[i] / A[j])
    //leaf node : initial dp[i]=1 we can construct every node as root because its leaf
    int numFactoredBinaryTrees(vector<int>& arr) {
        vector<int> &A=arr;
        
        long result = 0;
        long mod = pow(10, 9) + 7;
        
        sort(A.begin(), A.end());
        unordered_map<int, long> dp;
        
        for (int i = 0; i < A.size(); ++i) {
            dp[A[i]] = 1;
            for (int j = 0; j < i; ++j){
                 if (A[i] % A[j] == 0){
                     dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % mod;
                 }
            }  
            result = (result + dp[A[i]]) % mod;
        }
        return result;
        
        
    }
};
