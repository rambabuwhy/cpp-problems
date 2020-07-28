
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        while(l1 && l2){
            int sum = carry + l1->val + l2->val;
            carry = sum / 10;
            sum = sum % 10;

            ListNode* newNode = new ListNode(sum);
            if(!tail){
                head = tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int sum = carry + l1->val;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum);
            if(!tail){
                head = tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
            l1=l1->next;
        }
        while(l2){
            int sum = carry + l2->val;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum);
            if(!tail){
                head = tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }

            l2=l2->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            if(!tail){
                head = tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }
        return head;
     }
};
