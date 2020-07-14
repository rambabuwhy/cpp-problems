/*
You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        //base
        if(head == nullptr) return nullptr;
        
        //logic
        Node* dummy = new Node();
        flattenUtil(dummy,head);
        dummy->next->prev=nullptr;
        return dummy->next;
        
    }
    Node* flattenUtil(Node* prev,Node* curr){
        //base case
        if(curr == nullptr) return prev;
        
        curr->prev = prev;
        prev->next = curr;
        
        //flatten curr->child
        
        Node* temp_next = curr->next;
        
        Node *tail = flattenUtil(curr, curr->child);
        
        curr->child = nullptr;
        //flatten curr->next;
        
        return flattenUtil(tail, temp_next);
        
        
        
    }
};
