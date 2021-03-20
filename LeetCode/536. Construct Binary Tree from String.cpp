/*

You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.

 

Example 1:


Input: s = "4(2(3)(1))(6(5))"
Output: [4,2,6,3,1,5]
Example 2:

Input: s = "4(2(3)(1))(6(5)(7))"
Output: [4,2,6,3,1,5,7]
Example 3:

Input: s = "-4(2(3)(1))(6(5)(7))"
Output: [-4,2,6,3,1,5,7]

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
    
    //recursive
    //
    TreeNode* str2tree(string s) {
        if(s.empty()) return nullptr;
        
        return util(s,0).first;
        
    }
    
    pair<TreeNode*, int> util (string &s, int index){
        
        if(index == s.size()){
            
            return {nullptr,index};
        }
        
        int digit = getDigit(s, index);
                
        TreeNode * node = new TreeNode(digit);
        pair<TreeNode*,int> data;
        
        if(index < s.size() && s[index] == '('){
            
            data = util(s, index+1);
            node->left = data.first;
            index = data.second;
        }
        
        if(node->left != nullptr && index <s.size() && s[index] == '('){
            
            data = util(s, index+1);
            node->right = data.first;
            index = data.second;
        }
        
        if(index < s.size() && s[index]==')'){
            
            return {node, index +1};
            
        }
        else{
            return {node, index};
        }
        
        
    }
    
    int getDigit(string &s, int &index) {
        
        bool neg = false;
        
        if(s[index] == '-'){
            neg = true;
            index++;
        }
        
        int digit = 0;
         while(index < s.size() && isdigit(s[index]) ) {
             digit = digit * 10 + (s[index] - '0');
             index++;
         }
               
        return neg ? -digit : digit;
        
    }
};
