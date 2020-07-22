/*

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(root == nullptr) return vector<vector<int>>();
     
        vector<vector<int>> result;
        
        queue<TreeNode*> Q;
        Q.push(root);
       
        bool LR = true;
        while( Q.empty() == false ) {
            
            int cSize = Q.size();
            vector<int> cList;
            
            for(int i = 0; i < cSize; i++) {
            
                TreeNode *curr = Q.front();
                Q.pop();
               
                cList.push_back(curr->val);
                
               
                if(curr->left) Q.push(curr->left);
                if(curr->right) Q.push(curr->right);
                    
               
             
            } 
            if(!LR) reverse(cList.begin(),cList.end());
           
            result.push_back(cList);
            LR = !LR;
            
            
        }
        
        return result;
        
    }
};
