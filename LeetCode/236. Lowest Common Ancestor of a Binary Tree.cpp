/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
        
        //if found in left return 1
        int left  = util(root->left, p, q) ? 1: 0;
        
        //if found in right return 1
        int right = util(root->right, p, q) ? 1: 0;
        
        //if found in current  return 1
        int mid = (root == p || root ==  q ) ? 1: 0;
        
        //if atleast 2  then  lca
        if(left + right + mid >= 2)
        lca = root;
        
        //if  found atleast 1 return true
        return (left + right + mid > 0);
        
    }
    
private:
    TreeNode* lca;
};
