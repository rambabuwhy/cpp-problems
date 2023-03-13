/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
medium: https://rambabuy.medium.com/
Problem: Symmetric Tree
------------------------------------------------------------------
Description:
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false


------------------------------------------------------------------
Solution:
To check whether a binary tree is symmetric or not, we need to traverse the tree in a specific way. One way to do this is to use a recursive approach. We can define a helper function that takes two nodes as arguments and checks if they are symmetric. 
Then, we can call this function on the left and right children of the root node.

In the isSymmetric function, we first check if the root node is null, in which case we return true. Otherwise, we call the isSymmetricHelper function on the left and right children of the root node.

The isSymmetricHelper function checks if the two nodes are symmetric by recursively calling itself on their left and right children. It returns true if both nodes are null, or if they have the same value and their left and right children are symmetric. Otherwise, it returns false.




------------------------------------------------------------------
Notes:

Overall, this code has a time complexity of O(n), where n is the number of nodes in the tree, since we need to visit every node in the tree once. 
The space complexity is also O(n), since the recursive calls use a call stack that is proportional to the height of the tree.


------------------------------------------------------------------
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return isSymmetricHelper(root->left, root->right);
    }

private:
    bool isSymmetricHelper(TreeNode* leftNode, TreeNode* rightNode) {
        if (!leftNode && !rightNode) {
            return true;
        }
        if (!leftNode || !rightNode) {
            return false;
        }
        if (leftNode->val != rightNode->val) {
            return false;
        }
        return isSymmetricHelper(leftNode->left, rightNode->right) &&
               isSymmetricHelper(leftNode->right, rightNode->left);
    }
};

