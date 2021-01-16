/*

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass?

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
       ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *p1 = dummy;
        ListNode *p2 = dummy;
        
        while(p1 && n+1>0){
            p1 = p1->next;
            n--;
        }
        
            
        while(p1){
            p1 = p1->next;
            p2 = p2->next;
        }
        
        
        p2->next = p2->next->next;
        
        return dummy->next;
    }
};
