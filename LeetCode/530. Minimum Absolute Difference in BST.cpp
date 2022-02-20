/*
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 
 */


class Solution {
public:
    
    //INORDER TRAVESAL
    int val=-1;
    int diff = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        
        if (root->left != NULL)  {
            getMinimumDifference(root->left);
        }
        
        if (val >= 0) {
            diff = min(diff, root->val - val);
        }
        val = root->val;
        
        if (root->right != NULL)  {
            getMinimumDifference(root->right);
        }
        return diff;
    }
    
};
