/*

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


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
   
    bool isValidBST(TreeNode* root) {
        return util(root, LONG_MIN, LONG_MAX);
    }
    
    bool util(TreeNode* root, long low, long high) {
        
        if(root == nullptr)  
        return true;
        
        if(root->val <= low || root->val >= high)
        return false;
        
        return util(root->left, low, root->val) && util(root->right, root->val, high);
    } 
};
