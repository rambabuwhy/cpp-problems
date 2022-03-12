/*
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        // make linked list into the ring
        ListNode *tail = head;
        int list_size=1;
        while(tail->next){
            list_size++;
            tail=tail->next;            
        }
        tail->next = head;

        // find new tail : (n - k % n - 1)th node
        // and new head : (n - k % n)th node
        tail = head;
        for (int i = 0; i < list_size - k % list_size-1 ; i++){
             tail = tail->next;
        }         
        head = tail->next;

        // break the ring
        tail->next = nullptr;

        return head;
        
    }
};
