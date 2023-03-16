/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
medium: https://rambabuy.medium.com/
Problem: Maximum Depth of Binary Tree

------------------------------------------------------------------

Description:
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2


------------------------------------------------------------------

Solution:
In this code, TreeNode is assumed to be a class with an int value and pointers to the left and right child nodes, and the maxDepth function takes a pointer to the root node of the binary tree.

The function first checks if the root is nullptr, which is the base case for the recursive algorithm when the tree is empty. If the root is not nullptr, it computes the maximum depth of the left and right subtrees recursively by calling maxDepth on the left and right child nodes, respectively. 
Finally, it returns the maximum of the left and right depths plus one, which is the depth of the entire tree rooted at the current node.


------------------------------------------------------------------

Notes:
Yes, the recursive approach used in the implementation I provided is an optimized solution to compute the maximum depth of a binary tree in terms of time and space complexity. The time complexity of this solution is O(n), where n is the number of nodes in the tree, as we visit each node exactly once. The space complexity of this solution is also O(n), as we use the call stack to keep track of the recursion and we can have at most n frames on the call stack when the tree is a degenerate tree (i.e., a linked list).

Therefore, this approach is optimal in terms of both time and space complexity.


------------------------------------------------------------------
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
};


//comments added
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: if the root is null, the depth of the tree is zero
        if (root == nullptr) {
            return 0;
        }
        
        // Compute the maximum depth of the left subtree recursively
        int leftDepth = maxDepth(root->left);
        
        // Compute the maximum depth of the right subtree recursively
        int rightDepth = maxDepth(root->right);
        
        // Return the maximum depth of the left and right subtrees plus one
        // to account for the current node
        return max(leftDepth, rightDepth) + 1;
    }
};


//BFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // If the root is null, the depth of the tree is zero
        if (root == nullptr) {
            return 0;
        }
        
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            
            // Process all nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Add the left and right child nodes to the queue
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            // Increment the depth after processing all nodes at the current level
            depth++;
        }
        
        // Return the maximum depth of the tree
        return depth;
    }
};
