/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        
        if (root == nullptr) return 0;
        
        queue<TreeNode*> lq;
        
        lq.push(root);
        
        int minDepth = 0;
        while(!lq.empty()){
            minDepth++;
            
            int size = lq.size();
            for(int i=0; i<size; i++){
                TreeNode* curr = lq.front();
                lq.pop();
                
                if(curr->left == nullptr &&  curr->right == nullptr){
                    return minDepth;
                }
                
                if(curr->left) lq.push(curr->left);
                if(curr->right) lq.push(curr->right);      
            }             
        }
        return -1;
    }
};
