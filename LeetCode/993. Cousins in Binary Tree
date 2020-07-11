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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            bool S = false;
            bool C = false;
            int QS = Q.size();
            for(int i = 0 ; i < QS; i ++){
                TreeNode *Curr = Q.front();
                Q.pop();
                if(Curr == nullptr) S = false;
                else {
                    if(Curr->val == x || Curr->val == y){
                        if(C == false){
                            C = S = true;
                        }else{
                            return !S;
                        }
                    }
                    if(Curr->left) Q.push(Curr->left);
                    if(Curr->right) Q.push(Curr->right);
                    Q.push(nullptr);
                }
               
            }
            if (C) return false;
            
        }
        return false;
        
    }
};
