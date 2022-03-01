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
    
    //DFS iterative
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(root == nullptr) return vector<int>();
        
        vector<int> result;
        stack<TreeNode*> stack;
        
        TreeNode* curr = root;
        while(curr || !stack.empty()){
            
            //traverse left till end
            while(curr){
                stack.push(curr);
                curr = curr->left;
            }
            
            //pop; backtrack
            curr = stack.top();
            stack.pop();
            
            //right
            result.push_back(curr->val);
            curr= curr->right;   
        }
        return result;
    }
};
