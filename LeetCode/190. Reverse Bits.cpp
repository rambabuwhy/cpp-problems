/*

Reverse bits of a given 32 bits unsigned integer.

*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result = 0;
        int pow = 31;
        while(n){
            result = result | (n & 1) << pow;
            n = n >> 1;
            pow = pow -1;
            
        }
        return result;
        
    }
};
