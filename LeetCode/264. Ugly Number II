class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return false;  
        if(n == 1) return true; 
        int i2 = 0, i3 = 0, i5 = 0; 
        vector<int> k(n);
        k[0] = 1;
        for(int i  = 1; i < n ; i ++)
        {
            k[i] = min(k[i2]*2,min(k[i3]*3,k[i5]*5));
            if(k[i] == k[i2]*2) i2++; 
            if(k[i] == k[i3]*3) i3++;
            if(k[i] == k[i5]*5) i5++;
        }
        return k[n-1];
        
    }
};
