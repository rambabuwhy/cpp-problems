/*
Given a complete binary tree, count the number of nodes.
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
    int Count(TreeNode* root){
        if(!root) return 0;;
        
        int lcnt = Count(root->left);
        int rcnt = Count(root->right);
        return lcnt + rcnt + 1;
        
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return Count(root);
        
    }
};
