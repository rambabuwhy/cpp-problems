/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21

*/

class Solution {
public:
    int reverse(int x) {
        int result=0;
       
        while(x){
            
            //step 1: find last digit
            int digit = x%10;
            
            //check overflow
            if (result > INT_MAX/10 || (result == INT_MAX / 10 && digit > 7)) return 0;
            if (result < INT_MIN/10 || (result == INT_MIN / 10 && digit < -8)) return 0;
            
            //step 2: add that digit in reverse way
            result = result  * 10 +  digit;
            
            x = x/10;
        }
        
        return result;   
    }
};
