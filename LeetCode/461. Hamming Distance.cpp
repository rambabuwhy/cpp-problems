class Solution {
public:
    int hammingDistance(int x, int y) {
        int X = x ^ y;
        int count = 0;
        while(X){
            count++;
            X = X & (X-1);
            
        }
        
        return count;
        
    }
};
