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
/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

*/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        if(root == nullptr) return vector<double>();
        
        queue<TreeNode*>  lq;
        lq.push(root);
        
        vector<double> result;
        while(!lq.empty()){
            
            int size = lq.size();
            double ctotal = 0;
            for(int i=0; i<size; i++) {
                
                TreeNode* curr = lq.front();
                lq.pop();
                
                ctotal = ctotal + curr->val;
                
                if(curr->left) lq.push(curr->left);
                if(curr->right)  lq.push(curr->right);
                
            }
            
            result.push_back(ctotal/size);
            
            
        }
        
        return result;
        
    }
};
