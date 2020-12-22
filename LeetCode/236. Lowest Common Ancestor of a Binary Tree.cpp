/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        lca= nullptr;
        util(root, p, q);
        return lca;
    }
    
    bool util(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root ==  nullptr) 
        return false;
        
        int left  = util(root->left, p, q) ? 1: 0;
                
        int right = util(root->right, p, q) ? 1: 0;
        
        int mid = (root == p || root ==  q ) ? 1: 0;
        
        if(left + right + mid >= 2)
        lca = root;
        
        
        return (left + right + mid > 0);
        
    }
    
private:
    TreeNode* lca;
};
