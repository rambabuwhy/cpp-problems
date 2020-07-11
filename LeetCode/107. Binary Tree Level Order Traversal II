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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if ( root == nullptr )  return vector<vector<int>>();
        vector<vector<int>> result;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            int Lsize = Q.size();
            vector<int> clq;
            for(int i =0; i<Lsize; i++){
                TreeNode* n = Q.front();
                Q.pop();
                clq.push_back(n->val);
                if(n->left != nullptr) Q.push(n->left);
                if(n->right != nullptr) Q.push(n->right);
            }
            result.push_back(clq);
        }
        reverse(result.begin(), result.end());
        return result;
        
    }
};
