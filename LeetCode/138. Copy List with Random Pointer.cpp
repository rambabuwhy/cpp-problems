/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
 

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    unordered_map<Node*, Node*> umap;
    
    Node* getClonedNode(Node* node){
        
        if(node){
            
            if(umap.find(node) !=  umap.end()){
                return umap[node];  
            }
            else{ 
                umap[node] = new Node(node->val);
                return umap[node];
            } 
        }
        
        return nullptr;
        
        
    }
    
    Node* copyRandomList(Node* head) {
        
        if(head == nullptr)
        return head;
        
        Node* oldNode = head;
        Node* newNode = new Node(oldNode->val);
        
        umap[oldNode] = newNode;
        
        while(oldNode){
            
            newNode->random = getClonedNode(oldNode->random);
            newNode->next = getClonedNode(oldNode->next);
            
            oldNode = oldNode->next;
            newNode = newNode->next;
            
            
            
        }
        
        return umap[head];
        
    }
};
