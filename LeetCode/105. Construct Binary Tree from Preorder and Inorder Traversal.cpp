/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]

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
    
    //1. construct nodes from preorder[pre-index++]
    //2. find div_index  from inorder  (via map)
    //3. construct node->left  from inorder to divindex : util(inorder_start, div_index)
    //4. construct node->right from divindex to inorder : util(div_index+1, inorder_end)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int in_start = 0;
        int in_end = inorder.size();
        
        //value->index  of inorder
        for(int i = 0; i<inorder.size(); i++){
            umap[inorder[i]] = i;
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
        int divide_index = umap[root_val];
        
        TreeNode* root = new TreeNode(root_val);
        root->left = util(preorder, inorder, in_start, divide_index);
        root->right = util(preorder, inorder, divide_index+1, in_end);
        
        return root;
    }
    
private:
    unordered_map<int,int> umap;
    int pre_index;
};
