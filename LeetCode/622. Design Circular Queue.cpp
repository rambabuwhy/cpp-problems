/*
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implementation the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
 

Example 1:

Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]

Explanation
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4
*/


class MyCircularQueue {
public:
    
    struct LinkedList{
        int val;
        LinkedList *next;
    };
    
    LinkedList *head = nullptr;
    LinkedList *tail = nullptr;
    int count = 0;
    int capacity = 0;
    
    MyCircularQueue(int k) {
        capacity = k;
        
    }
    
    bool enQueue(int value) {
        
        if(count == capacity) return false;
        
        LinkedList *node = new LinkedList();
        node->val = value;
        node->next = nullptr;
        
        if(count == 0){
            head = tail = node;
           
        }
        else{
            tail->next = node;
            tail = node;
            
        } 
        count++;
        
        return true;
        
        
        
    }
    
    bool deQueue() {
        
        if(count == 0) return false;
        
        head = head->next;
        count--;
        return true;
        
    }
    
    int Front() {
        if(count == 0)  return -1;
        return head->val;
        
    }
    
    int Rear() {
        
        if(count == 0) return -1;
        return tail->val;
        
    }
    
    bool isEmpty() {
        
        return count == 0;
        
    }
    
    bool isFull() {
        
        return count == capacity;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
