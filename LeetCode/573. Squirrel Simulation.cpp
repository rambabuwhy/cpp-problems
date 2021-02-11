/*
There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid. Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one. The squirrel can only take at most one nut at one time and can move in four directions - up, down, left and right, to the adjacent cell. The distance is represented by the number of moves.
Example 1:

Input: 
Height : 5
Width : 7
Tree position : [2,2]
Squirrel : [4,4]
Nuts : [[3,0], [2,5]]
Output: 12

*/

class Solution {
public:
    
    int distance(vector<int> &a, vector<int> &b){
        
        return abs(a[0]-b[0]) + abs(a[1] - b[1]);
    }
    
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts)     {
        
        int total = 0;
        int d = INT_MIN;
        
        for(int i =0; i<nuts.size(); i++){
            total = total + distance(nuts[i],tree) * 2;
            d = max(d, distance(nuts[i], tree) - distance(nuts[i], squirrel));
            
        }
        
        return total - d;
        
    }
};
