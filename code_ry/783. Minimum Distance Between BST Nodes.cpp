/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
Problem: Minimum Distance Between BST Nodes

------------------------------------------------------------------

Description:
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1


------------------------------------------------------------------

Solution:
To find the minimum difference between any two different nodes in a binary search tree, we need to perform an in-order traversal of the tree, as the in-order traversal of a binary search tree results in a sorted list of nodes.

During the traversal, we keep track of the previous node visited and calculate the difference between the current node and the previous node.
We take the minimum of these differences and return it as the result.

We first initialize the minimum difference to be INT_MAX (maximum possible value for an int) and the previous node's value to be -1. 
We then perform the in-order traversal by calling the inOrderTraversal function.

The inOrderTraversal function takes the current node, previous node's value, and minimum difference as input. 
It recursively traverses the left subtree, then calculates the difference between the current node and the previous node (if there is a previous node), and updates the minimum difference accordingly. 
It then updates the previous node's value to the current node's value and recursively traverses the right subtree.

After the traversal, we return the minimum difference as the result.


------------------------------------------------------------------

Notes:
The time complexity of the algorithm is O(N), where N is the number of nodes in the binary search tree. This is because we are performing an in-order traversal of the tree, which visits each node exactly once.

During the traversal, we perform constant time operations such as updating the previous node's value and calculating the difference between the current and previous nodes. Thus, the overall time complexity of the algorithm is O(N).

Note that the space complexity of the algorithm is O(H), where H is the height of the binary search tree, as the maximum number of recursive calls on the call stack is equal to the height of the tree. 
In the worst case, when the tree is skewed, the height of the tree can be equal to the number of nodes, so the space complexity can be O(N). However, in a balanced tree, the height is typically logarithmic in the number of nodes, resulting in a space complexity of O(log N).


------------------------------------------------------------------
*/

#include<climits>

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;  // initialize the minimum difference to be maximum possible value
        int prevVal = -1;       // initialize the previous node's value to -1

        inOrderTraversal(root, prevVal, minDiff); // perform in-order traversal

        return minDiff;
    }
private:
    void inOrderTraversal(TreeNode* node, int& prevVal, int& minDiff) {
        if (node == nullptr) {
            return;
        }

        // recursively traverse the left subtree
        inOrderTraversal(node->left, prevVal, minDiff);

        if (prevVal != -1) {  // if there is a previous node
            minDiff = min(minDiff, node->val - prevVal);  // calculate the difference between current and previous node and update minimum difference
        }

        prevVal = node->val;  // update previous node's value to current node's value

        // recursively traverse the right subtree
        inOrderTraversal(node->right, prevVal, minDiff);
    }
};

