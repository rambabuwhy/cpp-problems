/*
ou are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
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

struct compare{
    
    bool operator()(ListNode* l, ListNode* r){
        return l->val > r->val;
    }
    
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        //priority queue:  push all list pointers means push pointer to first node
        //comparator: top element is minimum node value
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(int i=0; i<lists.size(); i++){ 
            if(lists[i]) pq.push(lists[i]);
        }
        
        if(pq.empty()) return nullptr;
        
        //result is always outside of the priority queue: 
        //add from top of the priority queue
        ListNode* result = pq.top();
        pq.pop();
        
        //save head; because result will move forwors as node added
        ListNode* new_head = result;
        if(result->next) pq.push(result->next);
        while(!pq.empty()){
            
            result->next = pq.top();
            pq.pop();
            result = result->next;
            
            if(result->next) pq.push(result->next);   
        }
        return new_head;
    }
};
