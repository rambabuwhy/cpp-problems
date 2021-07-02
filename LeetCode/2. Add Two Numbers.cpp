
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    
    //use dummy pointer
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        int carry = 0;
        while(l1 || l2){
            
            //if list is null add 0 other wise list value
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            
            int sum = carry + v1 + v2;
            carry = sum / 10;
            
            curr->next  = new ListNode(sum % 10);
            curr = curr->next;
            
            //move forward
            l1 ? l1 = l1->next : l1 = nullptr;
            l2 ? l2 = l2->next : l2 = nullptr;
        }
    
        carry > 0 ? curr->next = new ListNode(carry) : nullptr;
        
        return dummy->next;
    }
};
