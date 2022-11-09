/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 
 
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
  
    //fast and slow method
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }


    /*
    //find size and mid method
    ListNode* middleNode(ListNode* head) {
        
        //sanity
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        
        //find size of the list
        int count = 0;
        ListNode *curr=head;        
        while(curr){
            count++;
            curr = curr->next;
        }

        //find middle                
        int mid = count / 2; 
        curr=head;
        while( mid > 0 ) {            
            curr = curr->next;
            mid -- ;
        }
        return curr;        
    }
    */

    
};
