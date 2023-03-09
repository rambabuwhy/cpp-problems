/*

Author: Rambabu Yerajana
Linkedin: https://www.linkedin.com/in/rambabuyerajana/
medium: https://rambabuy.medium.com/
Problem: 
------------------------------------------------------------------
Description:
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.


------------------------------------------------------------------
Solution:
The algorithm starts by checking whether the linked list is empty or only has one node, in which case there can't be a cycle.

Then, two pointers, slow and fast, are initialized to the head of the linked list. The fast pointer moves twice as fast as the slow pointer. If there is a cycle, the two pointers will eventually meet at some point.

When the pointers meet, a cycle has been found. To find the starting node of the cycle, a new pointer temp is initialized to the head of the list. Then, temp and slow are moved at the same pace until they meet again. The node they meet at is the starting node of the cycle.

If the fast pointer reaches the end of the list without meeting the slow pointer, then there is no cycle in the list and nullptr is returned.

------------------------------------------------------------------
Notes:

The time complexity of the algorithm to find the starting node of a cycle in a linked list is O(n), where n is the number of nodes in the list.

The reason for this is that the algorithm iterates through each node in the list at most twice: once using the slow pointer, and once using the temp pointer. Since the maximum number of nodes that can be visited is twice the number of nodes in the list, the time complexity is O(n).

The space complexity of the algorithm is O(1) since only a constant amount of extra space is used, namely the two pointers slow and fast and the temporary pointer temp. Therefore, the space complexity is independent of the size of the input and is constant.
------------------------------------------------------------------
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) { // if the list is empty or only has one node, there can't be a cycle
            return nullptr;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) { // fast pointer moves twice as fast as slow pointer, if there's a cycle, they will eventually meet
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) { // a cycle is found, move a new pointer from head and meet the slow pointer to find the starting node
                ListNode* temp = head;
                while (temp != slow) {
                    temp = temp->next;
                    slow = slow->next;
                }
                return temp; // return the starting node of the cycle
            }
        }
        
        return nullptr; // no cycle found
    }
};

