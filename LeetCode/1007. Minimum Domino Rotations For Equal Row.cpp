/*
In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.

 

Example 1:


Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
*/

class Solution {
public:
    // tops/bottoms any are the same.
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        // A[0]: A or B equal to A[0]
        int top_rotations = check(tops[0], bottoms, tops, tops.size());
        if (top_rotations != -1 || tops[0] == bottoms[0]) return top_rotations;
        
        // B[0]: A or B equal to B[0]
        int bottom_rotations = check(bottoms[0], bottoms, tops, tops.size());
        if (bottom_rotations != -1 || tops[0] == bottoms[0]) return bottom_rotations;
        
        return -1;
    }
    
    int check(int x, vector<int>& A, vector<int>& B, int n) {
        
        int rotations_a = 0, rotations_b = 0;
        for (int i = 0; i < n; i++) {
          
            // if any row not equal to x: rotation not possible
            if (A[i] != x && B[i] != x) return -1;
          
            // A need rotation
            else if (A[i] != x) rotations_a++;
          
            // B need rotation    
            else if (B[i] != x) rotations_b++;
        }
        return min(rotations_a, rotations_b);
  }
};
