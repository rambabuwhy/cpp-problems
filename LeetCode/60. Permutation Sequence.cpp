/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence

*/

class Solution {
public:
    string getPermutation(int n, int k) {
        
        string D = "";
                
        for(int i = 1; i<=n; i++){
            char c = i + '0';
            D = D + c;
        }
        
        // Look-up table, which stores (n-1)!, (n-2)!, ..., 1!, 0!
        // Start from n-3,  last two are 1 ( 0!, 1!)
        vector<int> fract(n, 1);
        for (int idx = n - 3; idx >= 0; --idx) {
            fract[idx] = fract[idx + 1] * (n - 1 - idx);
        }
        --k;
        string result(n, 0);
        for (int idx = 0; idx < n; ++idx) {
            int select = k / fract[idx];
            k %= fract[idx];
            result[idx] = D[select];
            D.erase(next(D.begin(), select)); 
        }
        return result;
    
        
    }
};
