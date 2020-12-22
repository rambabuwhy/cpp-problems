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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int in_start = 0;
        int in_end = inorder.size();
        
        int pre_start = 0;
        int pre_end = preorder.size()-1;
        
        for(int i = 0; i<inorder.size(); i++){
            M[inorder[i]] = i;
        }
        
        pre_index = 0;
        
                
        TreeNode* root = util(preorder, inorder, in_start, in_end);
        return root;
    }
    
    TreeNode* util( vector<int>& preorder, 
                    vector<int>& inorder,
                    int in_start, int in_end ) {
        
        if(in_start == in_end)
        return nullptr;
        
        int root_val = preorder[pre_index];
        TreeNode* root = new TreeNode(root_val);
        
        int divide_index = M[root_val];
               
        pre_index++;
        
        root->left = util(preorder, inorder, in_start, divide_index);
        root->right = util(preorder, inorder, divide_index+1, in_end);
        
        
        return root;
    }
    
private:
    map<int,int> M;
    int pre_index;
};
