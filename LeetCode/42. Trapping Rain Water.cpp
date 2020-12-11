/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

*/

class Solution {
public:
    int trap(vector<int>& height) {
        
        //base
        if(height.size() == 0) return 0;
        vector<int> &H = height;
        
        
        
        vector<int> L(H.size());
        vector<int> R(H.size());
        int result=0;
        
        
        //fill L
        L[0]=H[0];
        for(int i = 1;i<H.size();i++)
        L[i] = max(H[i],L[i-1]);
        
        //fill R
        R[H.size()-1]=H[H.size()-1];
        for(int i = H.size()-2;i>=0;i--)
        R[i] = max(H[i],R[i+1]);
        
        
        //find result
        for(int i = 0;i<H.size();i++)
        result = result + min (L[i],R[i]) - H[i];
        
        
        return result;
        
        
        
        
    }
};
