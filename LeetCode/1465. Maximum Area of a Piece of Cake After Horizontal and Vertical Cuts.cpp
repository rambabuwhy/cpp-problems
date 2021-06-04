
/*
Given a rectangular cake with height h and width w, and two arrays of integers horizontalCuts and verticalCuts where horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.

Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a huge number, return this modulo 10^9 + 7.

 

Example 1:



Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4 
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.
Example 2:



Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.
Example 3:

Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9

*/


class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        //MOD for overflow check
        const int MOD = 1e9 + 7;
        
        long int ans = 0, maxWidth = 0, maxHeight = 0;
        
        //to find last row and last coloum
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        sort(begin(horizontalCuts), end(horizontalCuts));
        sort(begin(verticalCuts), end(verticalCuts));
        
        //find max height
        for (int i = 0, prev = 0; i < horizontalCuts.size(); i++) {
            maxHeight = max(maxHeight, (long int) horizontalCuts[i] - prev);
            prev = horizontalCuts[i];
        }
        
        //find max width
        for (int i = 0, prev = 0; i < verticalCuts.size(); i++) {
            maxWidth = max(maxWidth, (long int) verticalCuts[i] - prev);
            prev = verticalCuts[i];
        }
        
        //find maxWidth * maxHeight
        return (maxWidth * maxHeight) % MOD;
        
    }
};
