/*

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

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
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return preorder(nums, 0, nums.size()-1);
    }
    
    TreeNode* preorder(vector<int> &nums, int left, int right){
        
        if( left > right) return nullptr;
            
        int mid = (left + right) / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = preorder(nums, left, mid-1);
        root->right = preorder(nums, mid+1, right);
        
        return root;
        
    }
};
