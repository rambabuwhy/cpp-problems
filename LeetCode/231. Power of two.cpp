/*
Given an integer, write a function to determine if it is a power of two.

*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n == 0 )  return  false;
        long x = n;
        return (x & (x-1)) == 0;
        
    }
};
