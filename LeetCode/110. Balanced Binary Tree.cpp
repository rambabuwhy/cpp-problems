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
    bool isBalanced(TreeNode* root) {
        return util(root) == -1 ? false: true;
    }
    
    //return -1  for all unbalanced scenaios
    int util(TreeNode* root) {
        
        if(root == nullptr)
        return 0;
        
        int left = util(root->left);
        if(left == -1) return -1;
        
        int right = util(root->right);
        if(right == -1) return -1;
        
        if(abs(right - left) > 1)
        return -1;
        
        return max(left, right) + 1;
        
    }
};
