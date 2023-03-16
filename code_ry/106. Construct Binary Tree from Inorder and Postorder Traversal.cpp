/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
medium: https://rambabuy.medium.com/
Problem: Construct Binary Tree from Inorder and Postorder Traversal
------------------------------------------------------------------
Description:


Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]


------------------------------------------------------------------
Solution:
In the main function, we create an unordered map inorder_map to store the indices of each element in the inorder traversal. We then call the helper function buildTreeHelper, passing in the postorder traversal, starting and ending indices for the subtree in postorder, inorder_map, and starting and ending indices for the subtree in inorder.

In the helper function, we first check if the subtree is empty, i.e., if the starting index is greater than the ending index in either traversal. If so, we return nullptr.

Otherwise, we get the root value from the last element of the postorder traversal. We then find its index in the inorder traversal using inorder_map. We calculate the size of the left subtree using the index difference.

We create a new TreeNode with the root value and recursively call buildTreeHelper to construct the left and right subtrees. We pass in the updated indices for the subtrees based on the size of the left subtree.

Finally, we return the root of the binary tree.


------------------------------------------------------------------
Notes:
To construct a binary tree from inorder and postorder traversals, we need to first understand the characteristics of these traversals.

Inorder traversal: Left subtree -> Root -> Right subtree
Postorder traversal: Left subtree -> Right subtree -> Root

The last element of the postorder traversal corresponds to the root of the binary tree. 
Using this root element, we can find its position in the inorder traversal. 
All the elements to the left of the root in the inorder traversal form the left subtree of the binary tree, and all the elements to the right form the right subtree.

We can use this approach recursively to construct the binary tree. Here's the C++ code to do so:


------------------------------------------------------------------
*/

#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Create a map to store the indices of each element in the inorder traversal
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        
        // Call the helper function to construct the binary tree
        return buildTreeHelper(postorder, 0, postorder.size() - 1, inorder_map, 0, inorder.size() - 1);
    }
    
private:
    TreeNode* buildTreeHelper(vector<int>& postorder, int post_start, int post_end, 
                              unordered_map<int, int>& inorder_map, int in_start, int in_end) {
        // Base case: if the subtree is empty, return nullptr
        if (post_start > post_end || in_start > in_end) {
            return nullptr;
        }
        
        // Get the root value from the last element of the postorder traversal
        int root_val = postorder[post_end];
        
        // Find the index of the root value in the inorder traversal using the map
        int root_index = inorder_map[root_val];
        
        // Calculate the size of the left subtree based on the index difference
        int left_size = root_index - in_start;
        
        // Create a new TreeNode with the root value
        TreeNode* root = new TreeNode(root_val);
        
        // Recursively construct the left subtree
        root->left = buildTreeHelper(postorder, post_start, post_start + left_size - 1, inorder_map, in_start, root_index - 1);
        
        // Recursively construct the right subtree
        root->right = buildTreeHelper(postorder, post_start + left_size, post_end - 1, inorder_map, root_index + 1, in_end);
        
        // Return the root of the binary tree
        return root;
    }
};
