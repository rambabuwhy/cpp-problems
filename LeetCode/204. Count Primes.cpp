/*

Count the number of prime numbers less than a non-negative number, n.

*/

class Solution {
public:
    int countPrimes(int n) {
        
        if(n<2)  return 0;
        
        vector<bool> dp(n,true);
        
        dp[0]  = false;
        dp[1] =  false;
        
        for(int i = 2; i<sqrt(n); i++){
            
            if(dp[i] == true){
                
                for(int j=i*i;  j<n;  j=j+i){
                    dp[j]= false;
                }
               
            }
        }
        
        int result = count(dp.begin(),dp.end(),true);
        cout<<result;
        
        return  result;
        
    }
};
