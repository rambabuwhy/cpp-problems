/*
Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

 

Example 1:

Input: root = [2,1,3]
Output: [2,1,3]
Example 2:

Input: root = []
Output: []

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
https://leetcode.com/problems/serialize-and-deserialize-bst/Figures/449/tree_struct.png */
class Codec {
public:

       // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeUtil(root,out);
        return out.str();
        
    }

    void serializeUtil(TreeNode* root, ostringstream &out){
        if (root) {
            out << root->val << ' ';
            serializeUtil(root->left, out);
            serializeUtil(root->right, out);
        } else {
            out << "# ";
        }    
    }
    

   
    TreeNode* deserialize(string data) {
        int pos = 0;
        istringstream in(data);
        return deserializeUtil(in, pos, INT_MIN, INT_MAX);
    }
    
    inline TreeNode* deserializeUtil(istringstream &in, int& pos, int minValue, int maxValue) {
        string val;
        in >> val;
        if (val == "#") return nullptr;
        
        int ival = stoi(val);
        if (ival < minValue || ival > maxValue) return NULL;
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeUtil(in, pos, minValue, ival);
        root->right = deserializeUtil(in, pos, ival, maxValue);
        return root;
    }
};
