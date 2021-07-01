/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root == nullptr)
        return vector<vector<int>>();
        
        vector<vector<int>>  result;
        queue<TreeNode*> Q;
        
        Q.push(root);
        
        while(!Q.empty()){
            
            int size = Q.size();
            vector<int> curr_level;
            for(int i =0; i<size; i++){
                
                TreeNode* curr = Q.front();
                Q.pop();
                
                curr_level.push_back(curr->val);
                
                if(curr->left)
                Q.push(curr->left);
                
                if(curr->right)
                Q.push(curr->right);     
            } 
            result.push_back(curr_level);        
        }  
        return result;   
    }
};
