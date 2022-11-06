/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.

*/

class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int oldcolor,int newcolor){
        
        if(image[sr][sc] != oldcolor) return; //check if it is old color in current block
        else  image[sr][sc]=newcolor;  //fill new color

        if(sr>0) dfs(image,sr-1,sc,oldcolor,newcolor);
        if(sc>0) dfs(image,sr,sc-1,oldcolor,newcolor);
        if(sr<image.size()-1) dfs(image,sr+1,sc,oldcolor,newcolor);
        if(sc<image[0].size()-1) dfs(image,sr,sc+1,oldcolor,newcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        if(image[sr][sc] == color) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
        
    }
};
