/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

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
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*,int>> Q;
        Q.push( {root,0} );
        int result =0, currVal =0;
        while(!Q.empty()) {
            
            TreeNode *currNode = Q.front().first;
            currVal = Q.front().second;
            
            // curr node val + previous sum; 
            // previous sum already inserted in pair{}
            currVal        =  currVal * 10 + currNode->val;
            Q.pop();
            if(currNode->left == nullptr && currNode->right == nullptr){
                result = result + currVal;
            }
            if(currNode->left) Q.push( {currNode->left, currVal} );
            if(currNode->right) Q.push( {currNode->right, currVal} );
            
        }
        return result;
        
    }
};
