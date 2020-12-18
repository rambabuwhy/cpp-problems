/*

Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

*/

/*

Algorithm

step 1: 
    For each a in A.

        For each b in B.
        If a + b exists in the hashmap m, increment the value.
        Else add a new key a + b with the value 1.

step 2:
    For each c in C.

        For each d in D.
        Lookup key -(c + d) in the hashmap m.
        Add its value to the count cnt.

step 3: Return the count cnt.


*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        int count = 0;
        
        unordered_map<int,int> M;
        for(int a: A){
            for(int b: B){
                M[a+b]++;
            }
        }
        
        
        for(int c: C){
            for(int d: D) {
                auto itr = M.find(-(c+d));
                if(itr != end(M)){
                    count = count + itr->second;
                }
            }
        }
        
        
        return count;
        
    }
};
