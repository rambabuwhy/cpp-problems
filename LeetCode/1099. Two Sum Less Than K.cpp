/*
Given an array A of integers and integer K, return the maximum S such that there exists i < j with A[i] + A[j] = S and S < K. If no i, j exist satisfying this equation, return -1.

*/

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
    
        int result = -1;
        sort(A.begin(),A.end());
        
        int l = 0, h = A.size()-1;
        while(l<h){
            if(A[l]+A[h]<K){
                result = max(result,A[l]+A[h]);
                l++;
            }else{
                h--;
            }
        }
        
        return result;
        
    }
};
