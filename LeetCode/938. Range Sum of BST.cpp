/*
Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range [low, high].

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        
        if(root == nullptr) return 0;
        stack<TreeNode*> S;
        S.push(root);
        int result=0;
        while(!S.empty()){
            TreeNode* curr = S.top();
            S.pop();
            
            if(low <= curr->val && high >= curr->val) result = result + curr->val;
            if(low < curr->val && curr->left) S.push(curr->left);
            if(high > curr->val && curr->right) S.push(curr->right);
            
        }
        
        return result;
        
    }
};
