/*

Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True

*/

class Solution {
public:
    
    int dist(vector<int>& P1,vector<int>& P2){
        return (P1[0]-P2[0]) * (P1[0]-P2[0]) + (P1[1]-P2[1]) * (P1[1]-P2[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        unordered_set<int> S;
        S.insert(dist(p1,p2));
        S.insert(dist(p1,p3));
        S.insert(dist(p1,p4));
        S.insert(dist(p2,p3));
        S.insert(dist(p2,p4));
        S.insert(dist(p3,p4));
        
        //only two values  1. same side  2. same diagonal  
        return !S.count(0) && S.size() == 2;
        
    }
};
