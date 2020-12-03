/*

iven the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

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
    TreeNode* increasingBST(TreeNode* root) {
        
        if(root == nullptr)  return nullptr;
        
        increasingBST(root->left);
        
        if(newRoot == nullptr)
        newRoot = new TreeNode(0), curr = newRoot;
        
        
        root->left = nullptr;
        curr->right = root;
        curr = root;
        
        
            
        increasingBST(root->right);
        
        return newRoot->right;
        
    }
private:
    TreeNode *newRoot;
    TreeNode *curr;
};
