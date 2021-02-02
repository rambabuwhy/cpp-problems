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
    
    //1. construct node from preorder[pre-index++]
    //2. find div_index  from inorder  (MAP)
    //3. construct node->left  from inorder to divindex : util(inorder_start, div_index)
    //4. construct node->right from divindex to inorder : util(div_index+1, inorder_end)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int in_start = 0;
        int in_end = inorder.size();
        
        //value->index  of inorder
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
        
        int root_val = preorder[pre_index++];
        int divide_index = M[root_val];
        
        TreeNode* root = new TreeNode(root_val);
        root->left = util(preorder, inorder, in_start, divide_index);
        root->right = util(preorder, inorder, divide_index+1, in_end);
        
        return root;
    }
    
private:
    map<int,int> M;
    int pre_index;
};
