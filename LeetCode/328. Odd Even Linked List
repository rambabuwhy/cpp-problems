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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == nullptr) return head;
        // four pointers for odd head/tail  and even head/tail
        ListNode* oddHead =  head;
        ListNode* oddTail = head;
        ListNode* evenHead = head->next;
        ListNode*  evenTail = head->next;
        
        //traverse both tail pointers.
        while(oddTail != nullptr && oddTail->next != nullptr){
           
            oddTail->next = evenTail->next;
            if(oddTail->next)
            oddTail = oddTail->next;
            
            evenTail->next = oddTail->next;
            if(evenTail->next)
            evenTail = evenTail->next;
      
        }
        
        //merge odd and even  
        
        oddTail->next=evenHead;
        
        return head;
        
    }
};
