/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
Problem: Find Duplicate Subtrees

------------------------------------------------------------------

Description:
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

 

Example 1:


Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
Example 2:


Input: root = [2,1,1]
Output: [[1]]
Example 3:


Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]


------------------------------------------------------------------

Solution:

The idea of the solution is to serialize the subtrees of the binary tree and store them in a hash map. Since two subtrees are considered duplicate if they have the same structure with the same node values, we can use a string representation of the subtree to check for duplicates. 
We use a preorder traversal of the binary tree to serialize the subtrees, and null nodes are represented by the symbol #.

The serialize() function recursively serializes a subtree rooted at node. It first serializes the left subtree, then the right subtree, and finally concatenates the serialized strings with the current node's value to form the serialized string representation of the subtree.
If this is the first occurrence of the subtree, we add it to the hash map mp with its string representation as the key and a SubtreeInfo structure as the value. 
The SubtreeInfo structure stores the serialized string representation, the count of the subtree (which is initially 1), and the root node of the subtree. If this is the second occurrence of the subtree, we add its root node to the result vector res and increment its count in mp.

The findDuplicateSubtrees() function simply calls serialize() to serialize the entire binary tree and store the duplicate subtrees in res. Finally, it returns res, which contains the root nodes of all duplicate subtrees.


------------------------------------------------------------------

Notes:

This solution has a time complexity of O(n^2) in the worst case, where n is the number of nodes in the binary tree, since we need to serialize all subtrees and compare them with each other. 
However, in practice, the hash map lookup and string concatenation operations are usually very fast, so the actual running time is much faster than the worst case. 
The space complexity is O(n) in the worst case, since we need to store the serialized string representations of all subtrees in the hash map.

A more optimized solution could use a hash map to keep track of the subtrees that have already been seen and their frequency.
This way, we can avoid traversing the same subtree multiple times.

------------------------------------------------------------------
*/

// A structure to store the subtree and its count
struct SubtreeInfo {
    string str;     // serialized string representation of the subtree
    int count;      // count of this subtree
    TreeNode* root; // root of this subtree
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, SubtreeInfo> mp;
        vector<TreeNode*> res;
        serialize(root, mp, res); // serialize the tree and store duplicate subtrees in 'res'
        return res;
    }
    
    // Serialize the tree and store duplicate subtrees in 'mp' and 'res'
    string serialize(TreeNode* node, unordered_map<string, SubtreeInfo>& mp, vector<TreeNode*>& res) {
        if (!node) {
            return "#"; // null nodes are represented by '#'
        }
        
        string str = to_string(node->val) + "," + serialize(node->left, mp, res) + "," + serialize(node->right, mp, res);
        
        // If this is the first occurrence of this subtree, add it to 'mp'
        if (mp.find(str) == mp.end()) {
            mp[str] = { str, 1, node };
        }
        // If this is the second occurrence of this subtree, add it to 'res' and update the count in 'mp'
        else if (mp[str].count == 1) {
            res.push_back(mp[str].root);
            mp[str].count++;
        }
        
        return str;
    }
};

//more optimized
// A more optimized solution could use a hash map to keep track of the subtrees that have already been seen and their frequency.
//This way, we can avoid traversing the same subtree multiple times.

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> subtreeFreq;
        vector<TreeNode*> duplicates;
        traverse(root, subtreeFreq, duplicates);
        return duplicates;
    }
    
private:
    string traverse(TreeNode* node, unordered_map<string, int>& subtreeFreq, vector<TreeNode*>& duplicates) {
        if (!node) {
            return "#";
        }
        string left = traverse(node->left, subtreeFreq, duplicates);
        string right = traverse(node->right, subtreeFreq, duplicates);
        string subtree = to_string(node->val) + "," + left + "," + right;
        if (++subtreeFreq[subtree] == 2) {
            duplicates.push_back(node);
        }
        return subtree;
    }
};


