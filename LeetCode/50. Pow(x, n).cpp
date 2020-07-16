/*

Implement pow(x, n), which calculates x raised to the power n.

*/

class Solution {
public:
    double myPow(double x, int n) {
        
        //answer in double  assign to 1  "NOT 1"
        double ans = 1;
       
        // convert n to long long
        long long N = n;
        
        //check negetive scenario
        if( N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        //assign to new variabe  , it may change if n < 0
        long long i = N;
        double curr = x;
        
        //if odd  multiply one extra "x"
        while(i){
            
            if((i % 2) == 1){
                ans = ans * curr;
                
            }
            curr = curr * curr;
            i = i / 2;
        }
        return ans;
    }
};
