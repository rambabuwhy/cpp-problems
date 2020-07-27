/*

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        //base case
        if(inorder.size() != postorder.size()) return nullptr;
        
        //fill map
        for(int i = 0; i<inorder.size(); i++){
            Map[inorder[i]]= i;
        }
        
        //call util function
        post_index = postorder.size()-1;
        return buildTreeUtil(0,inorder.size()-1,inorder,postorder);
        
        
    }
    
    TreeNode* buildTreeUtil(int in_left, int in_right,vector<int>& inorder, vector<int>& postorder){
        
        //base case
        if(in_left > in_right) return nullptr;
        
        //get root node from postorder
        int root_val = postorder[post_index];
        TreeNode* root = new TreeNode(root_val);
        
        //get divider from index
        int in_index = Map[root_val];
        
        //decrement post index fot  postorder
        post_index--;
            
        //recursive after  divide the elements
        root->right = buildTreeUtil(in_index+1, in_right,inorder,postorder);
        root->left = buildTreeUtil(in_left, in_index-1, inorder,postorder);
        return root;
        
    }
    
private:
    unordered_map<int,int> Map;
    int post_index;
};
