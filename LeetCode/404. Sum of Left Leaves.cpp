/*
Given the root of a binary tree, return the sum of all left leaves.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0

*/


class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
        if (root == nullptr){
            return 0;
        }
        
        if(root->left == nullptr && root->right ==nullptr){
            return 0;
        }
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        int result = 0;
        while(!Q.empty()){
            
            TreeNode *curr=Q.front();
            Q.pop();
                
            if(curr->left && curr->left->left==nullptr && curr->left->right == nullptr){
                result = result + curr->left->val;
            }
            
            if(curr->left) Q.push(curr->left);
            if(curr->right) Q.push(curr->right);
            
        }
        
        return result;
        
    }
};
