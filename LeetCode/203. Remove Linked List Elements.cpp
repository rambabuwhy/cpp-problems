/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []

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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head == nullptr) return nullptr;
        
        //dummy ListHead    
        ListNode* dummy = new ListNode(0);
        dummy->next = head;        
        
        //three pointers  1. previous  2. current 3.delete
        ListNode *prev = dummy;
        ListNode *curr = head;
        ListNode *del = nullptr;        
        
        while(curr != nullptr){
            
            //find node assign del pointer
            if(curr->val == val){
                prev->next=curr->next;
                del = curr;
            }
            else{
                prev = curr;
            }
            
            //move curr pointer
            curr = curr->next;
            
            //garbage: delete del pointer
            if(del != nullptr){
                delete del;
                del = nullptr;
            }     
        }        
        return dummy->next;
    }
};
