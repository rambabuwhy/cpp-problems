/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
Problem: Binary Tree Zigzag Level Order Traversal

------------------------------------------------------------------

Description:
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


------------------------------------------------------------------

Solution:
In this solution, we use two stacks to store the nodes of the current level and the nodes of the next level. We also use a boolean variable to keep track of the order in which we add nodes to the next level stack. 
If leftToRight is true, we add the left child first and then the right child to the next level stack. 
If leftToRight is false, we add the right child first and then the left child to the next level stack. 
After we finish processing the nodes of the current level, we swap the current level stack with the next level stack and toggle the leftToRight variable to change the order of traversal for the next leve


------------------------------------------------------------------

Notes:
This solution is optimized in terms of time complexity, with a time complexity of O(n) where n is the number of nodes in the binary tree.

This is because we are traversing each node in the tree exactly once, and performing constant-time operations for each node. We use two stacks to store the nodes of the current level and the nodes of the next level, but the maximum size of each stack is the number of nodes in the last level of the tree, which is at most (n/2) nodes.

The space complexity of this solution is also O(n), as we are storing the values of all the nodes in the result vector. However, if we are only interested in printing out the values of the nodes in a zigzag level order, we can modify the algorithm to print the values as we traverse the tree, without using any additional space to store the result.

Overall, this solution is an efficient and optimal way to perform a zigzag level order traversal of a binary tree in C++.

--
Let's say we have the following binary tree:

markdown
Copy code
        1
       / \
      2   3
     / \   \
    4   5   6
We want to perform a zigzag level order traversal of this tree, which means that we need to traverse the tree in the following order:

Traverse the first level from left to right: 1
Traverse the second level from right to left: 3, 2
Traverse the third level from left to right: 4, 5, 6
So the expected output of the zigzag level order traversal of this tree is:

csharp
Copy code
[
  [1],
  [3, 2],
  [4, 5, 6]
]
Now let's see how the DFS solution we discussed earlier would traverse this tree:

We start by adding the root node to the current level stack: currentLevel = [1]
We set the leftToRight flag to true, which means we traverse the nodes from left to right on the first level
We enter the main loop of the algorithm, which continues until the current level stack is empty:
We initialize an empty vector levelValues to store the values of nodes in the current level
We pop a node from the current level stack: node = 1, currentLevel = []
We add the value of the node to the levelValues vector: levelValues = [1]
We add the children of the node to the next level stack from left to right: nextLevel = [2, 3]
We add the levelValues vector to the result vector: result = [[1]]
We swap the current level stack and the next level stack: currentLevel = [2, 3], nextLevel = []
We reverse the order of traversal for the next level by setting the leftToRight flag to false
We continue the loop with the new current level stack:
We initialize a new empty vector levelValues
We pop a node from the current level stack: node = 3, currentLevel = [2]
We add the value of the node to the levelValues vector: levelValues = [3]
We add the children of the node to the next level stack from right to left: nextLevel = [6]
We pop another node from the current level stack: node = 2, currentLevel = []
We add the value of the node to the levelValues vector: levelValues = [3, 2]
We add the children of the node to the next level stack from right to left: nextLevel = [5, 4]
We add the levelValues vector to the result vector: result = [[1], [3, 2]]
We swap the current level stack and the next level stack: currentLevel = [5, 4], nextLevel = []
We reverse the order of traversal for the next level by setting the leftToRight flag to true
We continue the loop with the new current level stack:
We initialize a new empty vector levelValues
We pop a node from the current level stack: node = 4, currentLevel = [5]
We add the value of the node to the
------------------------------------------------------------------
*/


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    // Initialize an empty vector to store the result
    vector<vector<int>> result;

    // Check if the root is NULL, return empty result
    if (root == NULL) {
        return result;
    }

    // Initialize two stacks to store the nodes of the current level and the next level
    stack<TreeNode*> currentLevel;
    stack<TreeNode*> nextLevel;

    // Add the root node to the current level stack
    currentLevel.push(root);

    // Initialize a flag to keep track of the order of traversal
    bool leftToRight = true;

    // Traverse the binary tree using DFS
    while (!currentLevel.empty()) {
        // Initialize an empty vector to store the values of nodes in the current level
        vector<int> levelValues;

        // Traverse all nodes in the current level
        while (!currentLevel.empty()) {
            // Pop a node from the current level stack
            TreeNode* node = currentLevel.top();
            currentLevel.pop();

            // Add the value of the node to the levelValues vector
            levelValues.push_back(node->val);

            // Add the children of the node to the next level stack
            if (leftToRight) {
                if (node->left != NULL) {
                    nextLevel.push(node->left);
                }
                if (node->right != NULL) {
                    nextLevel.push(node->right);
                }
            } else {
                if (node->right != NULL) {
                    nextLevel.push(node->right);
                }
                if (node->left != NULL) {
                    nextLevel.push(node->left);
                }
            }
        }

        // Add the levelValues vector to the result vector
        result.push_back(levelValues);

        // Swap the current level stack and the next level stack
        swap(currentLevel, nextLevel);

        // Reverse the order of traversal for the next level
        leftToRight = !leftToRight;
    }

    // Return the result vector
    return result;
}
