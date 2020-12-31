
/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> stk;
        
        stk.push(-1);
        
        int maxArea = 0;
        for(int i =0; i<heights.size(); i++){
            
            while((stk.top() != -1) && heights[stk.top()] >= heights[i]){
                
                int current_h = heights[stk.top()];
                stk.pop();
                
                int current_w = i - stk.top() -1;
                maxArea = max(maxArea, current_h * current_w);
                
            }
            
            stk.push(i);
            
        }
        
         while (stk.top() != -1) {
            int current_h = heights[stk.top()];
            stk.pop();
            int current_w = heights.size() - stk.top() - 1;
            maxArea = max(maxArea, current_h * current_w);
        }
        return maxArea;
        
        
        
        
    }
};
