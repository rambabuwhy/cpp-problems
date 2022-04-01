/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

*/

class MyQueue {
    stack<int> s1,s2;
public:
    MyQueue() {
        
    }
    
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    int pop(void) {
        peek();
        int x=s2.top();
        s2.pop();
        return x;
    }

    // Get the front element.
    int peek(void) {
        if (!s2.empty()) return s2.top();
        while (!s1.empty()) {
            int temp = s1.top();
            s2.push(temp);
            s1.pop();
        }
        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s2.empty() && s1.empty();
    }
};
