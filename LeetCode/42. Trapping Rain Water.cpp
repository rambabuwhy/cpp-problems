/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

*/

class Solution {
public:
    int trap(vector<int>& height) {
        
        //base
        if( height.size() == 0 ) return 0;
        
        vector<int> left (height.size());
        vector<int> right (height.size());
        int result=0;
       
        //fill Left side max height
        left[0]=height[0];
        for(int i = 1; i<height.size(); i++)
        left[i] = max(height[i], left[i-1]);
        
        //fill Right side  max height
        right[height.size()-1]= height[height.size()-1];
        for(int i = height.size()-2; i>=0 ;i--)
        right[i] = max (height[i], right[i+1]);
        
       //find result  min of left and right
        for(int i = 0; i<height.size(); i++)
        result = result + min(left[i], right[i])  - height[i];
         
        return result;
          
    }
};
