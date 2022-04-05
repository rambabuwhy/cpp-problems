/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false

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

//Recursive
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return util(root,root);
    }
    
    bool util(TreeNode* r1, TreeNode* r2){
       
        //if both null true; if not return false
        if(r1 == nullptr && r2 == nullptr) return true;
        if(r1 == nullptr || r2 == nullptr) return false;
        
        //if not match return false
        if(r1->val != r2->val) return false;
        
        //recursive both left and right
        return util(r1->left, r2->right) && util(r1->right, r2->left);
    }
};

//Iterative

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
        queue<TreeNode*> lq;
        lq.push(root);
        lq.push(root);
        
        while(!lq.empty()){
            
            TreeNode *left = lq.front();
            lq.pop();
            
            TreeNode *right=lq.front();
            lq.pop();
            
            if(left == nullptr && right == nullptr) continue;
            if(left == nullptr || right == nullptr) return false;
            if(left->val != right->val) return false;
            
            lq.push(left->left);
            lq.push(right->right);
            
            lq.push(left->right);
            lq.push(right->left);
            
        }
        
        return true;
    }
};
