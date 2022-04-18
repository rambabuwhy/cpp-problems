/*

Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3


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
    
    //iterative inorder: left -> process -> right
    int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode*> lstack;
        TreeNode* curr = root;
        
        int result;
        while(curr || !lstack.empty()){
            
            //left
            while(curr) {
                lstack.push(curr);
                curr = curr->left;
            }
            
            //process
            curr = lstack.top();
            lstack.pop();           
            if(--k == 0) return curr->val;
            
            //right
            curr = curr->right;
        }
        return result;
    }
};
