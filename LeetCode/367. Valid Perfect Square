class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 2 ) return true;
        int l = 2 , h=num/2;
        while(l<=h){
            int m = l + ( h - l)/2;
            long long sq = (long long ) m * m;
            if(sq == num) return true;
            if(sq > num) h = m -1;
            else l = m + 1;
        }
        return false;
        
    }
};
