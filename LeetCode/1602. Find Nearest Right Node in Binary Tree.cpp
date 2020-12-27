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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        
        if(root == nullptr) return nullptr;
        
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty()){
            
            int level_size = Q.size();
            for(int i =0; i<level_size; i++){
                
                TreeNode* curr = Q.front();
                Q.pop();
                
                if(u==curr){
                    if(i == level_size-1){
                        return nullptr;
                    }
                    else{
                        return Q.front();
                    }
                }
                
                if(curr->left) Q.push(curr->left);
                if(curr->right)  Q.push(curr->right);
                
                
            }
        }
        
        
        return nullptr;
        
        
    }
};
