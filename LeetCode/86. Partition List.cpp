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
/*

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]

*/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* first_head = new ListNode(0);
        ListNode* first_tail = first_head;
        
        ListNode* second_head = new ListNode(0);
        ListNode* second_tail = second_head;
        
        ListNode* curr=head;
        while(curr){
            
            if(curr->val < x){
                first_tail->next = curr;
                first_tail = curr;
                
            }else {
                
                second_tail->next = curr;
                second_tail = curr;             
            }
            
            curr = curr->next;           
            
        }
        
        second_tail->next=nullptr;
        first_tail->next= second_head->next;
        
        
        return first_head->next;
        
    }
};
