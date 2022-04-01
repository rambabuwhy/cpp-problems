/*

Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [1,2]
Example 5:


Input: root = [1,null,2]
Output: [1,2]

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
    vector<int> preorderTraversal(TreeNode* root) {
            
        if(root == nullptr) return vector<int>();
        stack<TreeNode*> stack;
        stack.push(root);
        
        vector<int> result; 
        while(!stack.empty()) {
           
            //store
            TreeNode* curr=stack.top();
            stack.pop();            
            result.push_back(curr->val); 
            
            //right then left because it is stack
            if(curr->right) stack.push(curr->right);
            if(curr->left) stack.push(curr->left);                       
        }
        return result;
    }
};
