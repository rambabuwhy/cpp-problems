/*
Given the root of a binary search tree and a node p in it, return the in-order successor of that node in the BST. If the given node has no in-order successor in the tree, return null.

The successor of a node p is the node with the smallest key greater than p.val.

 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    //iterative Method
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        //if right exist go one step right,` then go left dead end
        if(p->right != nullptr){
            p = p->right;
            while(p->left) p=p->left;
            return p;
        }
        
        //if no right  then find ancestor
        //if previousnode of currentnode is 'p' then  current node is succeessor
        stack<TreeNode*> lstack;
        TreeNode* prev = nullptr;
        TreeNode* curr=root;
        
        while(curr || !lstack.empty()) {
            
            while(curr != nullptr){
                lstack.push(curr);
                curr=curr->left;
            }
            
            curr=lstack.top();
            lstack.pop();
            
            if(prev == p) return curr;
            
            prev=curr;
            curr=curr->right;
        }
        
        return nullptr;
        
    }
};
