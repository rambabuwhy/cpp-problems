/*
Given a non-negative integer represented as a linked list of digits, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list.

 

Example 1:

Input: head = [1,2,3]
Output: [1,2,4]
Example 2:

Input: head = [0]
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
    ListNode* plusOne(ListNode* head) {
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* curr = dummy;
        
        ListNode* notNine = nullptr;
        
        
        //step 1:find non-Nine digit
        while(curr){
            
            if(curr->val  != 9)
            notNine = curr;
            
            curr =  curr->next;
        }
        
         //step 2: increament it
        notNine->val++;
        
        //step 3: change all next values to 0
        curr=notNine->next;
        while(curr){
            curr->val = 0;
            curr=curr->next;
        }
        
        if(dummy->val == 0)
        return dummy->next;
        
        else
        return dummy;
        
        
    }
};
