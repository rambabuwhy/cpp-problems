/*

Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

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
    int widthOfBinaryTree(TreeNode* root) {
        if ( root == nullptr) return 0;
        int result=0;
        queue<pair<TreeNode*,int>> Q;
        Q.push({root,0});
        
        while(!Q.empty()){
            
            int size = Q.size();
            long left = Q.front().second;
            long right = Q.front().second;
            
            for ( int i =0; i<size;i++){
                TreeNode* curr = Q.front().first;
                right=Q.front().second;
                Q.pop();
                if(curr->left) Q.push({curr->left,2 * right});
                if(curr->right) Q.push({curr->right, 2* right + 1});
            }
            result = max(result, (int)(right-left+1));
            
            
        }
        return result;
        
    }
};
