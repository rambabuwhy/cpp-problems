/*

Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:

B.length >= 3
There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
(Note that B could be any subarray of A, including the entire array A.)

Given an array A of integers, return the length of the longest mountain. 

Return 0 if there is no mountain.

*/
class Solution {
public:
    int longestMountain(vector<int>& A) {
        
        
        int result = 0;
        //S: Start  E:end
        int S = 0;
        while(S < A.size()){
            int E = S;
            
            //E from low to to top
            if(E +1 <A.size() && A[E]<A[E+1]){
                
                //E from low to to top
                while(E+1 < A.size() && A[E]<A[E+1]){
                    E++;
                }
                //E to top to low
                if(E+1<A.size() && A[E]>A[E+1]){
                    
                    //E to top to low
                    while(E+1<A.size() && A[E]>A[E+1]){
                        E++;
                    }
                    
                    result = max(result, E - S +1);
                }
            }
            
            //reset S
            S = max(E,S+1);
            
            
        }
        
        return result;
        
    }
};
