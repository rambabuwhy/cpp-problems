/*
Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]

*/

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        stack<TreeNode*> stack1;
        stack<TreeNode*> stack2;
       
        vector<int> result;

        while (root1 != nullptr || root2 != nullptr || !stack1.empty() || !stack2.empty()) {
      
            //push left of root1 
            while (root1 != nullptr) {
                stack1.push(root1);
                root1 = root1->left;
            }
            
            //push left of root2
            while (root2 != nullptr) {
                stack2.push(root2);
                root2 = root2->left;
            }

            //pop of both stack and move right
            if ( stack2.empty() || !stack1.empty() && stack1.top()->val <= stack2.top()->val) {
                root1 = stack1.top();
                stack1.pop();
                result.push_back(root1->val);
                root1 = root1->right;
            }
            else {
                root2 = stack2.top();
                stack2.pop();
                result.push_back(root2->val);
                root2 = root2->right;
            }
        }
        return result;
    }
};
