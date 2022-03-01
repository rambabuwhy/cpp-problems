/*
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

Example 1:


Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
*/

class Solution {
public:
    void recoverTree(TreeNode* root) {
        
        if ( root == nullptr) return;
        
        stack<TreeNode*> stack;
        
        TreeNode *curr=root;
        TreeNode *prev=nullptr;
        TreeNode *x=nullptr;
        TreeNode *y=nullptr;
        while(curr || !stack.empty()) {
            
            while(curr) {
                stack.push(curr);
                curr=curr->left;
            }
            
            curr=stack.top();
            stack.pop();
            
            if(prev && prev->val > curr->val) {
                y=curr;
                if(x==nullptr){
                    x=prev;
                } else{
                    break;
                }
            }
            prev=curr;
            curr= curr->right;
        }
        
        int temp = x->val;
        x->val=y->val;
        y->val=temp;
        
    }
};
