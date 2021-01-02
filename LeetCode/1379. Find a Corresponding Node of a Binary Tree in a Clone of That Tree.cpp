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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        queue<TreeNode*> QO;
        queue<TreeNode*> QC;
        
        QO.push(original);
        QC.push(cloned);
        
        while(! QO.empty()) {
            
            TreeNode* o_curr = QO.front();
            QO.pop();
            TreeNode* c_curr = QC.front();
            QC.pop();
            
            if(o_curr == target)
            return c_curr;
            
            if(o_curr->left) QO.push(o_curr->left);
            if(o_curr->right) QO.push(o_curr->right);
            
            if(c_curr->left) QC.push(c_curr->left);
            if(c_curr->right) QC.push(c_curr->right);
            
        }
        
        
        return nullptr;
        
    }
};
