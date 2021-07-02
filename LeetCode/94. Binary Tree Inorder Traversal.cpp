/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
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
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(root == nullptr)
        return vector<int>();
        
        vector<int> result;
        stack<TreeNode*> S;
        
        TreeNode*curr = root;
        while(curr || !S.empty()){
            
            while(curr){
                S.push(curr);
                curr = curr->left;
            }
            
            curr = S.top();
            S.pop();
            
            result.push_back(curr->val);
            
            curr= curr->right;   
        }
        return result;
    }
};
