/*

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

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
    
    pair<int,int> util( TreeNode *node ) {
	    if( !node ) return {0, 0};

	    auto left = util( node->left );
	    auto right = util( node->right );
        
        //with node: node val + without child
	    int withNode = node->val + left.second + right.second;
        
        //without node: max of childs
	    int withoutNode = max( right.first, right.second ) + max( left.first, left.second ); 
        
	    return { withNode, withoutNode };
    }
    int rob(TreeNode* root) {
        
        if(root == nullptr)  return 0;
        
        pair<int,int> result = util(root);
        return max(result.first,result.second);
     
    }
};
