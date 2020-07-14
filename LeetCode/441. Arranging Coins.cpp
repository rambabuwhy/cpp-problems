class Solution {
public:
    int arrangeCoins(int n) {
        long l = 0;
        long r = n;
        while ( l <= r){
            
            long m = l + (r-l)/2;
            
            long k = m * (m+1)/2;
            
            if( k == n)return (int)m;
            if( k < n) l = m + 1;
            else r = m - 1;
        }
        
        return (int)r;
    
    }
};
