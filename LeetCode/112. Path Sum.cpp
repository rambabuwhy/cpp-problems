/*

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Example 3:

Input: root = [1,2], targetSum = 0
Output: false

*/

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr) return false;
        
        targetSum = targetSum - root->val;
        if(root->left == nullptr && root->right == nullptr && targetSum == 0) return true;
    
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
