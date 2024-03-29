/*


Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [2,1]

*/

class Solution {
public:
    
    vector<int> result;
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(root){
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            result.push_back(root->val);
        }
        return result;
    }
};

class Solution {
public:    
    
    vector<int> postorderTraversal(TreeNode* root) {
    
        vector<int> result;
        stack<TreeNode*> lstack;
        
        TreeNode *curr = root;
        while(curr || !lstack.empty()) { 
            
            if(curr){
                lstack.push(curr);
                result.insert(result.begin(), curr->val);
                curr = curr->right;
            } else {
                curr = lstack.top();
                lstack.pop();
                curr = curr->left;
            }           
        }        
        return result;        
    }
};
