/*
A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end. For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.

 
 */
 
 
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        
        if(mat.size() < 2)
        return mat;
        
        unordered_map<int, priority_queue<int,vector<int>,greater<int>>> umap;
        
        
        for(int r =0; r <mat.size(); r++){
            for(int c =0; c<mat[0].size(); c++){
                
                umap[r-c].push(mat[r][c]);
            }
        }
        
        for(int r =0; r <mat.size(); r++){
            for(int c =0; c<mat[0].size(); c++){
                mat[r][c] = umap[r-c].top();
                umap[r-c].pop();
            }
        }

        
        return mat;
        
    }
};
