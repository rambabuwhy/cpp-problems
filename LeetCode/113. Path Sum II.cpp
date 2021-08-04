/*

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> result;
        vector<int> curr;
        
        util(root, targetSum, result, curr);
        return result;
        
    }
    
    void util(TreeNode* root, int targetSum, vector<vector<int>> &result, vector<int> &curr){
        
        if(root ==nullptr) return;
        
        curr.push_back(root->val);
        
        if(root->left == nullptr && root->right == nullptr && targetSum == root->val){
            result.push_back(curr);
        }
        
        util(root->left, targetSum - root->val, result, curr);
        util(root->right, targetSum - root->val, result, curr);
        
        curr.pop_back();
    }
};
