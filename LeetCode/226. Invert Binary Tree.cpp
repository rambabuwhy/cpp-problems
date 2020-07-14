/*
Invert a binary tree.
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* curr = Q.front();
            Q.pop();
            TreeNode* temp = curr->right;
            curr->right = curr->left;
            curr->left = temp;
            if(curr->left) Q.push(curr->left);
            if(curr->right) Q.push(curr->right);
            
        }
        return root;
        
    }
};
