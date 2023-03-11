/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
medium: https://rambabuy.medium.com/
Problem: 
------------------------------------------------------------------
Description:

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
height-balanced
 binary search tree.

 

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []


------------------------------------------------------------------
Solution:
The sortedListToBST function takes in the head of a singly linked list and returns a pointer to the root of a height-balanced binary search tree.

The function first checks if the linked list is empty (if (!head)) or contains only one element (if (!head->next)), in which case it simply creates a new TreeNode with the value of the head node and returns it.

If the linked list contains more than one element, the function finds the middle node of the linked list using the "slow and fast pointer" technique.
The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. When the fast pointer reaches the end of the list (i.e., fast == nullptr or fast->next == nullptr), the slow pointer will be pointing to the middle node.

The function then disconnects the linked list at the middle node by setting prev->next to nullptr, where prev is the node before the middle node.

It creates a new TreeNode for the middle node and sets its value to slow->val.

It then recursively constructs the left and right subtrees by calling sortedListToBST on the left and right halves of the original linked list, respectively. 
The left subtree is constructed using the original linked list from the beginning to the node before the middle node (head to prev), while the right subtree is constructed using the original linked list from the node after the middle node to the end (slow->next to nullptr).

Finally, the function returns a pointer to the root of the constructed binary search tree.


------------------------------------------------------------------
Notes:


------------------------------------------------------------------
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        if (!head->next) {
            return new TreeNode(head->val);
        }
        
        // Find the middle node of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Disconnect the linked list at the middle node
        if (prev) {
            prev->next = nullptr;
        }
        
        // Create a new TreeNode for the middle node
        TreeNode* root = new TreeNode(slow->val);
        
        // Recursively construct the left and right subtrees
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};

