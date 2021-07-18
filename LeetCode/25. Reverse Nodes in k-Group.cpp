/*

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Follow up:

Could you solve the problem in O(1) extra memory space?
You may not alter the values in the list's nodes, only nodes itself may be changed.


*/


//RECURSIVE METHOD

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
    //1: head is starting of list of k length
    //2: rev_head is pointting to lastnode of k length
    //3: return rev_head;
    ListNode* reverseKGroup(ListNode* head, int k) {
    
        ListNode * curr = head;
        int count = 0;
        
        //move curr to k nodes
        while(count < k && curr) { 
            curr = curr->next;
            count++;
        }
        
        if(count == k) {
            ListNode* rev_head = reverse(head, k);
            head->next = reverseKGroup(curr, k);
            return rev_head;
        }
        return head;
    }
    
    ListNode* reverse(ListNode* head, int k) {
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while(k>0) {
            
            ListNode* next = curr->next;    
            curr->next = prev;    
            prev = curr;
            curr = next;  
            k--;   
        }
        return prev;
    }
};
