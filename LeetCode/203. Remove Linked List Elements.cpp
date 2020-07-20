/*
Remove all elements from a linked list of integers that have value val.

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
        
        
        //three pointers  1. traverse  2.previous 3.delete
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
            
            //delete del pointer
            if(del != nullptr){
                delete del;
                del = nullptr;
            }
     
        }
        
        return dummy->next;

    }
};
