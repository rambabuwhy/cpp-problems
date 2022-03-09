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

//compare function for priority queue
struct compare {
    bool operator() (ListNode* a, ListNode* b){
        return (a->val) > (b->val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        //priority queue:  push all list pointers means push pointer to first node
        //comparator: top element is minimum node value
        priority_queue<ListNode*, vector<ListNode*>, compare> pq; //min q
        for(int i=0; i<lists.size(); i++){ 
            if(lists[i]) pq.push(lists[i]);
        }
        
        if(pq.empty()) return nullptr;
        
        //result is always outside of the priority queue: 
        ListNode* result = pq.top();
        pq.pop();
        
        ListNode* head = result;
        
        //After pop from Q , push next node in Q from same list.
        if(result->next) pq.push(result->next);
        while(!pq.empty()){
            
            result->next = pq.top();
            pq.pop();
            
            //After pop from Q , push next node in Q from same list.
            result = result->next;            
            if(result->next) {
                pq.push(result->next);   
            }
        }
        return head;
    }
};
