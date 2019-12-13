class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int result = 0;
        int i=x;
        while(i){
            if(result > INT_MAX/10 || result == INT_MAX/10 && i%10 >7) return false;
            result = result * 10 + i % 10;
            i /= 10;
        }
        return result == x;

    }
};
