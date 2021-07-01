/*

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


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
    int maxDepth(TreeNode* root) {
        
        if(root == nullptr) return 0;
        
        int  depth = 0;
        queue<TreeNode*> Q;
        Q.push(root);
   
        while( !Q.empty() ) {
            
            int qsize =  Q.size();
            for(int i = 0; i< qsize; i++) {
              
                TreeNode* curr = Q.front();
                Q.pop();
                
                if(curr->left)  Q.push(curr->left);
                if(curr->right) Q.push(curr->right);
            }
            depth++;     
        } 
        return depth;
    }
};
