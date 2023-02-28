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
solution 1:
The findDuplicateSubtrees function takes the root node of a binary tree as input and returns a vector containing the root nodes of all the duplicate subtrees in the tree. 
It first creates an unordered map m to store the serialized subtrees and their counts, and an empty vector res to store the root nodes of duplicate subtrees. 
It then calls the serialize function to serialize each subtree in the binary tree, updating m and res as necessary, and finally returns res.

The serialize function takes a pointer to a TreeNode, a reference to an unordered map m, and a reference to a vector res. 
It recursively serializes each subtree in the binary tree using a pre-order traversal. If the current node is NULL, it returns a special symbol "#". 
Otherwise, it serializes the subtree by concatenating the string representation of the current node's value with the serialized strings for the left and right subtrees, separated by commas. 
It then increments the count of the serialized subtree in the m map, and if the count is 2 (indicating that the subtree has appeared twice), it adds the root node of the subtree to the res vector. 
Finally, it returns the serialized string for the subtree.

Solution 2:
The idea of the solution is to serialize the subtrees of the binary tree and store them in a hash map. 
Since two subtrees are considered duplicate if they have the same structure with the same node values, we can use a string representation of the subtree to check for duplicates. 
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


//Solution 1:
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> m; // map to store serialized subtrees and their counts
        vector<TreeNode*> res; // vector to store root nodes of duplicate subtrees
        serialize(root, m, res); // serialize the subtrees and update the map and vector
        return res;
    }

private:
    string serialize(TreeNode* root, unordered_map<string, int>& m, vector<TreeNode*>& res) {
        if (!root) {
            return "#"; // represent empty node as a special symbol "#"
        }
        string s = to_string(root->val) + "," + serialize(root->left, m, res) + "," + serialize(root->right, m, res); // serialize the subtree
        if (++m[s] == 2) { // if the subtree appears for the second time, add the root to the result vector
            res.push_back(root);
        }
        return s;
    }
};

//Solution 2 same as above

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

//Solution 3:
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


