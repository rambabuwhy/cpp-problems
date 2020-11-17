/*

There is a special square room with mirrors on each of the four walls.  Except for the southwest corner, there are receptors on each of the remaining corners, numbered 0, 1, and 2.

The square room has walls of length p, and a laser ray from the southwest corner first meets the east wall at a distance q from the 0th receptor.

Return the number of the receptor that the ray meets first.  (It is guaranteed that the ray will meet a receptor eventually.)

*/

class Solution {
public:
    
    int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    
     int mirrorReflection(int p, int q) {
         
         
        //we need to know p/q :-  gcd of p and q 
        int g = gcd(p, q);
         
        p = p / g; 
        p = p % 2;
        q = q / g;
        q = q % 2;
         
        //out of three receiver opposite, left and right
        // Receiver 1:  if p and q are same , opposite

        if (p == 1 && q == 1) return 1;
         
        // Receiver 0 or 2 
        return p == 1 ? 0 : 2;
    }

    
};
