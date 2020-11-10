/*
Given a binary matrix A, we want to flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

*/


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        int C = A[0].size();
        
        for (vector<int> &R: A){
            //each row swap first and last with flipped until middle 
            //here middle is C + 1 /2  :- no of coloums / 2
            for (int i = 0; i < (C + 1) / 2; ++i) {
                int tmp = R[i] ^ 1;
                
                R[i] = R[C - 1 - i] ^ 1;
                R[C - 1 - i] = tmp;
            }
        }
        return A;
        
    }
};
