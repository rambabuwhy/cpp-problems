/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
medium: https://rambabuy.medium.com/
Problem: Check Completeness of a Binary Tree
------------------------------------------------------------------
Description:
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
Example 2:


Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.


------------------------------------------------------------------
Solution:
The basic idea behind this solution is to do a level-order traversal of the binary tree using a queue, while keeping track of whether we've found a null node (i.e., a node with no children). 
If we find a null node after we've already seen a non-null node, then the binary tree is not complete. Otherwise, the binary tree is complete.


------------------------------------------------------------------
Notes:
The time complexity of this solution is O(n), where n is the number of nodes in the binary tree. This is because we are visiting each node in the tree exactly once in a level-order traversal.

The space complexity of this solution is O(w), where w is the maximum width of the binary tree (i.e., the maximum number of nodes at any level). This is because we are using a queue to store the nodes at each level, and the size of the queue will be at most the width of the tree. 
In the worst case, where the binary tree is a complete binary tree, the width of the tree is O(n), so the space complexity is also O(n) in that case.


------------------------------------------------------------------
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
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> q;                 // create a queue to hold the nodes in the binary tree
        q.push(root);                       // add the root node to the queue
        bool found_null = false;            // keep track of whether we've found a null node in the binary tree
        while (!q.empty()) {                // while there are still nodes in the queue
            TreeNode* node = q.front();     // get the next node in the queue
            q.pop();                        // remove it from the queue
            if (node == nullptr) {          // if the node is null
                found_null = true;          // set found_null to true
            } else {                        // otherwise, the node is not null
                if (found_null) {           // if we've already found a null node
                    return false;           // the binary tree is not complete
                }
                q.push(node->left);         // add the left child of the node to the queue
                q.push(node->right);        // add the right child of the node to the queue
            }
        }
        return true;                        // if we've made it this far, the binary tree is complete
        
    }
};
