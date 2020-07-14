class Solution {
public:
    void dfs(vector<vector<int>> &image, int r, int c, int currColor, int newColor){
        if(currColor != image[r][c]) return;
        //currColor = image[r][c];
        image[r][c]=newColor;
        
        if(r > 0) dfs(image,r-1,c,currColor,newColor);
        if( c > 0 ) dfs (image,r,c-1,currColor,newColor);
        if(c+1 < image[0].size()) dfs (image,r,c+1,currColor,newColor);
        if(r+1 < image.size()) dfs (image,r+1,c,currColor,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if(color != newColor) dfs(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
};
