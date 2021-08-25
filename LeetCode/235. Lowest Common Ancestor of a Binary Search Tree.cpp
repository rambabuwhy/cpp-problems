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
        
        //BST: if root is in between p and q  then root is Ancestor
        //if root is less than p and q then we need to go right else left
        while(root){
            
            if(root->val < p->val && root->val < q->val) root = root->right;
            
            else if(root->val > p->val && root->val >q->val) root = root->left;
            
            else return root;   
        }
        return nullptr;
    }
};
