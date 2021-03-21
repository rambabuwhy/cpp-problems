/*
Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.

 

Example 1:

Input: 1
Output: true
Example 2:

Input: 10
Output: false
Example 3:

Input: 16
Output: true
Example 4:

Input: 24
Output: false
Example 5:

Input: 46
Output: true

*/

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        
        string S = to_string(N);
        vector<int> A(S.size());
        
        for (int i = 0; i < S.length(); ++i)
            A[i] = S[i] - '0';
        
        return permutations(A, 0);
    }
    
    bool permutations(vector<int> &A, int start) {
        if (start == A.size())
            return isPowerOfTwo(A);

        for (int i = start; i < A.size(); ++i) {
          
            swap(A[start], A[i]);

            if (permutations(A, start + 1)){
                 return true;
            }
               
            swap(A[start], A[i]);
        }

        return false;
    }
    
    bool isPowerOfTwo(vector<int> &A)
    {
        if (A[0] == 0){
            return false;
        }   

        int N = 0;
        for (int x: A) {
            N = 10 * N + x;
        }

       return (ceil(log2(N)) == floor(log2(N)));
    }
};
