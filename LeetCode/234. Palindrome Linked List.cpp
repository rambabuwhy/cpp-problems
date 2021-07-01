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
    bool isPalindrome(ListNode* head) {
        
        if(head == nullptr) return true;
        if(head->next == nullptr) return true;
        stack<int> lstk;
        
        //store into stack
        ListNode* curr=head;
        while(curr) {
            lstk.push(curr->val),curr= curr->next;
        }
        
        //compare with stack
        while(head && !lstk.empty()){
            if(head->val != lstk.top())  return false;
            
            lstk.pop();
            head= head->next;
        }
        
        return true;
        
    }
};



/******************************************************************************************
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
    
    ListNode *front=nullptr;
    
    bool isPalindrome(ListNode* head) {
        front = head;
        return reverse(head);        
    }
    
    bool reverse(ListNode *last){
        
        if(last == nullptr) return true; 
           
        if(reverse(last->next) == false) {
            return false;
        }
        
        if(front->val != last->val) {
            return false;
        }
        
        front = front->next;
        return true;
    }
};
