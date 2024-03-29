/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
medium: https://rambabuy.medium.com/
Problem: Invert Binary Tree

------------------------------------------------------------------

Description:
Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []


------------------------------------------------------------------

Solution:
We first define the TreeNode struct to represent a node in the binary tree. It contains an integer value val and pointers to its left and right children.

The Solution class contains the invertTree function that takes a TreeNode pointer as input and returns a TreeNode pointer as output.

Inside the function, we first check if the root node is null. If it is, we return NULL indicating that the node has no children.

If the node is not null, we swap its left and right children using a temporary variable temp.

Next, we recursively call invertTree on the left and right child of the current node. This will continue until we reach the base case of a node with no children.

Finally, we return the root of the inverted binary tree.

Note that this implementation modifies the original binary tree in place, so we don't need to create a new binary tree.


------------------------------------------------------------------

Notes:

The time complexity of the invertTree function is O(n), where n is the number of nodes in the binary tree.

This is because the function visits every node in the binary tree exactly once and performs a constant amount of work for each node.

The recursive calls to invertTree on the left and right child of each node also have a total time complexity of O(n), since each node is visited exactly once.

Therefore, the total time complexity of the invertTree function is O(n) + O(n) = O(n).

Note that this assumes that the binary tree is balanced. In the worst case, if the binary tree is highly unbalanced, the time complexity could be O(n^2). However, this is unlikely to occur in practice.


------------------------------------------------------------------
*/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // base case: if the node is null, return null
        if (!root) {
            return NULL;
        }
        
        // swap the left and right child of the current node
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // recursively call invertTree on the left and right child of the current node
        invertTree(root->left);
        invertTree(root->right);
        
        // return the root of the inverted binary tree
        return root;
    }
};


#include <queue>

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // swap the left and right child of the current node
                TreeNode* temp = node->left;
                node->left = node->right;
                node->right = temp;
                
                if (node->left) {
                    q.push(node->left);
                }
                
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        
        return root;
    }
};

/*
BFS:
We start by checking if the root node is null. If it is, we return NULL.

We create a queue of TreeNode pointers to store the nodes at each level of the binary tree. We push the root node onto the queue to start the BFS traversal.

While the queue is not empty, we process each level of the binary tree. We first get the size of the queue, which gives us the number of nodes at the current level.

We then loop through the nodes at the current level, popping each node from the front of the queue. For each node, we swap its left and right child using a temporary variable temp.

If the node has a left child, we push it onto the back of the queue. If the node has a right child, we also push it onto the back of the queue.

Once we have processed all the nodes at the current level, we move on to the next level by starting a new loop iteration.

Finally, we return the root node of the inverted binary tree.

The time complexity of this BFS approach is also O(n), where n is the number of nodes in the binary tree, since we visit each node exactly once. However, the space complexity is O(w), where w is the maximum width of the binary tree (i.e., the maximum number of nodes at any level). This is because we use a queue to store the nodes at each level, and the maximum number of nodes at any level is the width of the binary tree.

*/
