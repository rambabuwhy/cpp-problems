/*

Sort a linked list using insertion sort.

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
    ListNode* insertionSortList(ListNode* head) {
        
        if (head == NULL || head->next == NULL){
            return head;
      
        }
        
	    ListNode *curr = head->next;
	    head->next = NULL;

	    while (curr != NULL)
	    {
            ListNode *Next = curr->next;   
            ListNode *itr = head;
            //before head
            if (curr->val < itr->val)    
            {
                curr->next = itr;
                head = curr;
            }
            //if not traverse from head
            else 
            {
                while ( 
                    itr != NULL && 
                    itr->next != NULL && 
                    itr->next->val <= curr->val )  {
                    
                    itr = itr->next;
                }
                    
                curr->next = itr->next;
                itr->next = curr;
            }

		    curr = Next;
	    }
	    return head;
        
    }
};
