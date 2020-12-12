/*

Given the root of a binary tree, the depth of each node is the shortest distance to the root.

Return the smallest subtree such that it contains all the deepest nodes in the original tree.

A node is called the deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is tree consisting of that node, plus the set of all descendants of that node.

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
    
    pair<int, TreeNode*> util(TreeNode* root){
        
        if(root == nullptr)
        return {0, root};
        
        auto L = util(root->left);
        auto R = util(root->right);
        
        
        if(L.first == R.first)
        return {1+L.first, root};  //  both are same  return  root;
        
        else if(L.first > R.first)
        return {1+ L.first, L.second};
        
        else
        return {1+R.first, R.second};
        
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        if(root == nullptr )  
        return root;
        
        if(root->left == nullptr  &&  root->right == nullptr) 
        return  root;
        
        return util(root).second;
        
    }
};
