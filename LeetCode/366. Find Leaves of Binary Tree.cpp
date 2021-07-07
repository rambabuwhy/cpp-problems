/*

Given the root of a binary tree, collect a tree's nodes as if you were doing this:

Collect all the leaf nodes.
Remove all the leaf nodes.
Repeat until the tree is empty.
 

Example 1:


Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not matter the order on which elements are returned.
Example 2:

Input: root = [1]
Output: [[1]]

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
    
    vector<vector<int>> gvec;
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        gvec.clear();
        getHeight(root);
        return gvec;
        
    }
    
    //postorder: get height of all nodes
    //store same height nodes in same place using gvec 
    int getHeight(TreeNode* root) {
        
        if(root == nullptr) return -1;
        
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        
        int currHeight = 1+ max(leftHeight, rightHeight);
        
        //allocate 1D
        if(gvec.size() == currHeight){
            gvec.push_back({});
        }
        
        //push into 2D:  all which has same height into same vec
        gvec[currHeight].push_back(root->val);
        
        return currHeight;
    }
};
