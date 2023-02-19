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


------------------------------------------------------------------
*/


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == NULL) {
        return result;
    }

    stack<TreeNode*> currentLevel;
    stack<TreeNode*> nextLevel;
    bool leftToRight = true;
    currentLevel.push(root);

    while (!currentLevel.empty()) {
        vector<int> levelValues;
        int size = currentLevel.size();

        for (int i = 0; i < size; i++) {
            TreeNode* currentNode = currentLevel.top();
            currentLevel.pop();

            levelValues.push_back(currentNode->val);

            if (leftToRight) {
                if (currentNode->left != NULL) {
                    nextLevel.push(currentNode->left);
                }
                if (currentNode->right != NULL) {
                    nextLevel.push(currentNode->right);
                }
            } else {
                if (currentNode->right != NULL) {
                    nextLevel.push(currentNode->right);
                }
                if (currentNode->left != NULL) {
                    nextLevel.push(currentNode->left);
                }
            }
        }

        result.push_back(levelValues);
        leftToRight = !leftToRight;
        swap(currentLevel, nextLevel);
    }

    return result;
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Get the zigzag level order traversal of the tree
    vector<vector<int>> result = zigzagLevelOrder(root);

    // Print the result
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

