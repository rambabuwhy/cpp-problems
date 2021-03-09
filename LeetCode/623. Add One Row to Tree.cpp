/*
Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root node is at depth 1.

The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, create two tree nodes with value v as N's left subtree root and right subtree root. And N's original left subtree should be the left subtree of the new left subtree root, its original right subtree should be the right subtree of the new right subtree root. If depth d is 1 that means there is no depth d-1 at all, then create a tree node with value v as the new root of the whole original tree, and the original tree is the new root's left subtree.
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

/*
traverse till d-1
copy current nodes lef tand right into temp node
insert new node with value v at both left and right
assign temp nodes back to new nodes

*/
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
       
        if(d==1){
            TreeNode *newNode = new TreeNode(v);
            newNode->left = root;
            return newNode;
        }
        
        queue<TreeNode*> lq;
        lq.push(root);
        int depth =1;
        
        while(depth < d-1) {
            
            int size = lq.size();
            for(int i=0; i<size; i++) {
                TreeNode* curr=lq.front();
                lq.pop();
                if(curr->left) lq.push(curr->left);
                if(curr->right) lq.push(curr->right);             
            }
            depth++;           
        }
        
        while(!lq.empty()){
            
            TreeNode *curr = lq.front();
            lq.pop();
            
            TreeNode *leftNode = curr->left;
            curr->left = new TreeNode(v);
            curr->left->left= leftNode;
            
            TreeNode* rightNode = curr->right;
            curr->right = new TreeNode(v);
            curr->right->right = rightNode;
        }
        
        return root;
        
    }
};
