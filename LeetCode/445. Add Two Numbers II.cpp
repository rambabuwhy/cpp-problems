/*

ou are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

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
    
    ListNode *reverse(ListNode *head){
        
        ListNode *prev=nullptr;
        ListNode* curr=head;
        
        while(curr != nullptr){
            ListNode* next= curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        return prev;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //step1:  reverse both lists
        l1=reverse(l1);
        l2=reverse(l2);
        
        
        //step2:  add elementory addition
        int carry = 0,val=0;
        ListNode* head=nullptr;
        
        while(l1 != nullptr || l2 != nullptr){
            
            int val1 = l1!=nullptr ? l1->val:0;
            int val2 = l2!=nullptr ? l2->val:0;
            
            val = (val1 + val2 + carry) % 10;
            carry = (val1 + val2 + carry) / 10;
            
            ListNode *curr = new ListNode(val);
            curr->next=head;
            head=curr;
            
            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
            
        }
        
        if (carry != 0) {
            ListNode *curr = new ListNode(carry);
            curr->next = head;
            head = curr;
        }
        
        
        return head;
        
        
        
        
    }
};
